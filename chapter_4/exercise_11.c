/* Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint:
    use an internal static variable. */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */
#define MAXVAL  100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* reverse Polish calculator */
main()
{
    int type;
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
        case '\n':
            printf("\t%.8g\n", pop());
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
    int i;
    static int c = ' ';

    while (c == ' ' || c == '\t')
        s[0] = c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
        c = ' ';        /* read next character next time getop is run */
        return s[0];    /* not a number */
    }
    i = 0;
    if (isdigit(c) || c == '+' || c == '-') /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')   /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if ((s[0] == '+' || s[0] == '-') && i == 1)
        return s[0];    /* return operator if no digits afterwards */
    return NUMBER;
}
