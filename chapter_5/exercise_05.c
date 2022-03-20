/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and
    strncmp, which operate on at most the first n characters of their argument
    strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
    Full descriptions are in Appendix B. */
#include <stdio.h>

void my_strncpy(char *, char *, int);
void my_strncat(char *, char *, int);
int my_strncmp(char *, char *, int);

main()
{
    char s[14];

    my_strncpy(s, "hello, world\n", 7);
    printf("%s\n", s);
    my_strncat(s, "world\nabc", 6);
    printf("%s", s);
    printf("%d\n", my_strncmp(s, "hello, a", 7));
    return 0;
}

/* strncpy:  copy first n characters of t to s */
void my_strncpy(char *s, char *t, int n)
{
    for (; n > 0 && (*s++ = *t++) != '\0'; --n)
        ;
    if (n < 0)
        *s = '\0';
}

/* strncat:  concatenate first n characters of t to end of s */
void my_strncat(char *s, char *t, int n)
{
    while (*s++ != '\0')    /* find end of s */
        ;
    --s;    /* overwrite '\0' */
    for (; n > 0 && (*s++ = *t++) != '\0'; --n) /* copy t */
        ;
    if (n < 0)
        *s = '\0';
}

/* strncmp:  compare first n characters of s and t; return <0 if s < t, 0 if
    s == t, and >0 if t < s */
int my_strncmp(char *s,  char *t, int n)
{
    for (; n > 0 && *s == *t; s++, t++, --n)
        if (*s == '\0' || n == 1)
            return 0;
    return *s - *t;
}
