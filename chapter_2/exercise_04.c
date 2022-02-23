/* Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes each
    character in s1 that matches any character in the string s2. */
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int my_getline(char line[], int maxline);
void squeeze(char s1[], char s2[]);

/* testing code */
main()
{
    int c, i;
    char line[MAXLINE]; /* current input line */
    char s2[] = "abc";

    while (my_getline(line, MAXLINE) > 0) {
        squeeze(line, s2);
        printf("%s\n", line);
    }
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

/* squeeze:  delete all chars in s2 from s1 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}
