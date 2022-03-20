/* Exercise 5-4. Write the function strend(s,t), which returns 1 if the string
    t occurs at the end of the string s, and zero otherwise. */
#include <stdio.h>
#include <string.h>

int strend(char *, char *);

main()
{
    printf("%d\n", strend("hello, world\n", "world\n"));
    return 0;
}

/* strend:  return 1 if t occurs at the end of s, 0 otherwise */
int strend(char *s, char *t)
{
    for (; *s != '\0'; ++s)
        ;
    s -= strlen(t);
    for (; *s == *t; ++s, ++t)
        if (*s == '\0')
            return 1;
    return 0;
}
