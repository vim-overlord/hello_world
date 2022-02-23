/* Exercise 2-5. Write the function any(s1,s2), which returns the first
    location in the string s1 where any character from the string s2 occurs, or
    -1 if s1 contains no characters from s2. (The standard library function
    strpbrk does the same job but returns a pointer to the location.) */
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int my_getline(char line[], int maxline);
int any(char s1[], char s2[]);

/* testing code */
main()
{
    int c, i;
    char s1[MAXLINE];
    char s2[] = "abc";

    while (my_getline(s1, MAXLINE) > 0)
        if (any(s1, s2) >= 0)
            printf("First occurrence: %d\n", any(s1, s2));
    return 0;
}

/* getline:  read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* any:  return location of first occurence of any character from s2 in s1 */
int any(char s1[],  char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;
    return -1;
}
