/* Exercise 2-10. Rewrite the function lower, which converts upper case letters
    to lower case, with a conditional expression instead of if-else. */
#include <stdio.h>

int lower(int c);

/* testing code */
main()
{
    int c;

    for (c = 'A'; c <= 'Z'; ++c)
        putchar(lower(c));
    putchar('\n');
    return 0;
}

/* lower:  convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
