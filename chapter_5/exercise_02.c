/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What type
    does getfloat return as its function value? */
#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getch();
void ungetch(int);
int getfloat(double *);

int buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

main()
{
    double n;
    int temp;

    while ((temp = getfloat(&n)) != EOF) {
        if (temp != 0)
            printf("%f\n", n);
        else {
            printf("Error: not a number\n");
            break;
        }
    }
    return 0;
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

/* getfloat:  get next floating-point number from input into *pn */
int getfloat(double *pn)
{
    int c, sign, power;

    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);    /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c) && c != EOF) {
        ungetch(c);
        ungetch(c); /* unget sign */
        return 0;
    }
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    power = 1;
    if (c == '.') {
        c = getch();
        for (; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10;
        }
    }
    *pn *= sign;
    *pn /= power;
    if (c != EOF)
        ungetch(c);
    return c;
}
