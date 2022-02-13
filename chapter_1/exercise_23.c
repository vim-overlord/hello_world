/* Exercise 1-23. Write a program to remove all comments from a C program.
    Don’t forget to handle quoted strings and character constants properly. C
    comments do not nest. */
#include <stdio.h>

#define IN 1    /* inside a comment */
#define OUT 0   /* outside a comment */

main()
{
    int c;
    int state;  /* whether inside or outside of a comment */

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            c = getchar();
            if (c == '*') {
                state = IN;
                while (state == IN) {
                    c = getchar();
                    if (c == '*') {
                        c = getchar();
                        if (c == '/')
                            state = OUT;
                    }
                }
                c = getchar();
            } else
                putchar('/');
        }
        if (c == '"') {
            putchar(c);
            while ((c = getchar()) != '"') {
                putchar(c);
                /* ignore second character of escape sequence */
                if (c == '\\')
                    putchar(getchar());
            }
        }
        putchar(c);
        if (c == '\'') {    /* avoid treating '"' as start of string */
            if ((c = getchar()) == '\\') {
                putchar(c);
                c = getchar();
            }
            putchar(c);
            putchar(getchar());
        }
    }
    return 0;
}
