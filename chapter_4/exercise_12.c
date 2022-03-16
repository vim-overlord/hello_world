/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of
    itoa; that is, convert an integer into a string by calling a recursive
    routine. */
#include <stdio.h>

void itoa(int n, char s[]);

/* testing code */
main()
{
    char s[12];

    itoa(-100, s);
    printf("%s\n", s);
    return 0;
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    static int i = 0;

    if (n / 10)
        itoa(n / 10, s);
    else if (n < 0)
        s[i++] = '-';
    s[i++] = ((n >= 0) ? n : -n) % 10 + '0';
    s[i] = '\0';
}
