#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */
#define VAR     'A' /* signal that a variable was found */
#define SIN     'I' /* signal that a sin function was found */
#define EXP     'E' /* signal that a exp function was found */
#define POW     'O' /* signal that a pow function was found */
#define MAXVAL  100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
void print_val(void);
void duplicate(void);
void swap(void);
void clear(void);
void setvar(int, double);
double getval(int);
int getch(void);
void ungetch(int);
void ungets(char []);
int lookfor(char []);

int sp = 0;         /* next free stack position */
int ans = 0;        /* most recently printed value */
double val[MAXVAL]; /* value stack */
double var[26];     /* variable values */
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* reverse Polish calculator */
main()
{
    int type, temp;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                for (op1 = pop(); op1 >= op2; op1 -= op2)
                    ;
                push(op1);
            } else
                printf("error: zero divisor\n");
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case VAR:
            temp = s[0];
            break;
        case '&':
            push(getval(s[1]));
            break;
        case '=':
            setvar(temp, pop());
            push(getval(temp));
            break;
        case 'a':
            push(ans);
            break;
        case 'p':
            print_val();
            break;
        case 'd':
            duplicate();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        case '\n':
            if (sp == 1) {
                printf("\t%.8g\n", op1 = pop());
                ans = op1;
            }
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop:  get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
        if (islower(c)) {
            switch (c) {
                case 's':
                    return (lookfor("in")) ? SIN : c;
                case 'e':
                    return (lookfor("xp")) ? EXP : c;
                case 'p':
                    return (lookfor("ow")) ? POW : c;
                default:
                    return c;   /* not a number */
            }
        } else if (c == '&') {
            s[1] = getch();
            s[2] = '\0';
        } else if (isupper(c))
            return VAR;
        return c;
    }
    i = 0;
    if (isdigit(c) || c == '+' || c == '-') /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if ((s[0] == '+' || s[0] == '-') && i == 1)
        return s[0];    /* return operator if no digits afterwards */
    return NUMBER;
}

/* print_val:  print top element of value stack */
void print_val(void)
{
    if (sp > 0) {
        printf("\t%.8g\n", val[sp - 1]);
        ans = val[sp - 1];
    } else
        printf("error: stack empty\n");
}

/* duplicate:  duplicate top element of value stack */
void duplicate(void)
{
    if (sp > MAXVAL - 1) {
        printf("error: stack full, can't duplicate\n");
        return;
    } else if (sp <= 0) {
        printf("error: stack empty\n");
        return;
    }
    double temp = pop();

    push(temp);
    push(temp);
}

/* swap:  swap top two elements of value stack */
void swap(void)
{
    if (sp <= 1) {
        printf("swap: stack doesn't contain 2 elements\n");
        return;
    }
    double num_1 = pop();
    double num_2 = pop();

    push(num_1);
    push(num_2);
}

/* clear:  clear value stack */
void clear(void)
{
    sp = 0;
}

/* setvar:  set the value of a variable */
void setvar(int c, double f)
{
    if (isupper(c))
        var[c - 'A'] = f;
    else
        printf("error: invalid variable name\n");
}

/* getval:  return value of a variable */
double getval(int c)
{
    if (isupper(c))
        return var[c - 'A'];
    else {
        printf("error: invalid variable name\n");
        return 0;
    }
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets:  push character string back on input */
void ungets(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ;
    --i;    /* exclude \0 */
    for (; i >= 0; --i)
        ungetch(s[i]);
}

/* lookfor:  return 1 if specified string is found */
int lookfor(char s[])
{
    int i;
    char temp[MAXOP];

    for (i = 0; s[i] != '\0' && (temp[i] = getch()) == s[i]; ++i)
        ;
    if (s[i] == '\0')   /* string was found */
        return 1;
    else {  /* unget read string and return 0 */
        temp[i + 1] = '\0';
        ungets(temp);
        return 0;
    }
}
