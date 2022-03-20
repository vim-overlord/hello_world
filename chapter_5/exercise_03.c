/* Exercise 5-3. Write a pointer version of the function strcat that we showed
    in Chapter 2: strcat(s,t) copies the string t to the end of s. */
#include <stdio.h>

void my_strcat(char *, char *);

main()
{
    char s[14] = "hello, ";

    my_strcat(s, "world\n");
    printf("%s", s);
    return 0;
}

/* strcat:  concatenate t to end of s; s must be big enough */
void my_strcat(char *s, char *t)
{
    while (*s++ != '\0')    /* find end of s */
        ;
    --s;    /* overwrite '\0' */
    while ((*s++ = *t++) != '\0')   /* copy t */
        ;
}
