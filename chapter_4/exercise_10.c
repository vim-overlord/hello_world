/* Exercise 4-10. An alternate organization uses getline to read an entire
    input line; this makes getch and ungetch unnecessary. Revise the calculator
    to use this approach. */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#define MAXVAL  100     /* maximum depth of val stack */
#define MAXLINE 1000    /* maximum input line size */

int getop(char []);
void push(double);
double pop(void);
int my_getline(char s[], int lim);

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char line[MAXLINE]; /* current input line */
int lp = -1;        /* current position in line */

/* reverse Polish calculator */
main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while (my_getline(line, MAXLINE) > 0) {
        while ((type = getop(s)) != '\n') {
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
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
        printf("\t%.8g\n", pop());
        lp = -1;
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
    int i;

    while ((s[0] = line[++lp]) == ' ' || line[lp] == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(line[lp]) && line[lp] != '.' && line[lp] != '+' &&
        line[lp] != '-')
        return line[lp];    /* not a number */
    i = 0;
    /* collect integer part */
    if (isdigit(line[lp]) || line[lp] == '+' || line[lp] == '-')
        while (isdigit(s[++i] = line[++lp]))
            ;
    if (line[lp] == '.') /* collect fraction part */
        while (isdigit(s[++i] = line[++lp]))
            ;
    s[i] = '\0';
    if (line[lp] != EOF)
        --lp;
    if ((s[0] == '+' || s[0] == '-') && i == 1)
        return s[0];    /* return operator if no digits afterwards */
    return NUMBER;
}

/* getline:  get line into s, return length */
int my_getline(char s[], int lim)
{
    int i, c;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
