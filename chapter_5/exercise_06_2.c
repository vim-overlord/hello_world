/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and
    exercises with pointers instead of array indexing. Good possibilities
    include... itoa... reverse... */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000    /* maximum input line length */
#define swap(t, x, y) \
    t z = x; \
    x = y; \
    y = z;

void itoa(int, char *);
void reverse(char *);

main()
{
    char s[12];

    itoa(-128, s);
    printf("%s\n", s);
    return 0;
}

/* itoa:  convert n to characters in s */
void itoa(int n, char *s)
{
    int sign;
    char *p = s;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    do {       /* generate digits in reverse order */
        *s++ = n % 10 + '0';    /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(p);
}

/* reverse:  reverse string s in place */
void reverse(char *s)
{
    char *t = s + strlen(s) - 1;

    for (; t - s > 0; ++s, --t) {
        swap(char, *s, *t);
    }
}
