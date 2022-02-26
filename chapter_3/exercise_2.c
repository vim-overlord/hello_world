/* Exercise 3-2. Write a function escape(s,t) that converts characters like
    newline and tab into visible escape sequences like \n and \t as it copies
    the string t to s. Use a switch. Write a function for the other direction
    as well, converting escape sequences into the real characters. */
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int my_getline(char line[], int maxline);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

/* testing code */
main()
{
    int c, i;
    char line[MAXLINE]; /* current input line */
    char s[MAXLINE];    /* input line with visible escape sequences */

    while (my_getline(line, MAXLINE) > 0) {
        escape(s, line);
        printf("Escaped: %s\n", s);
        unescape(line, s);
        printf("Unescaped: %s\n", line);
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

/* escape:  copy string t to s and make escape sequences visible */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j] = 't';
            break;
        default:
            s[j] = t[i];
            break;
        }
        ++j;
    }
    s[j] = '\0';
}

/* unescape:  copy string t to s and make visible escape sequences invisible */
void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\\':
            switch (t[++i]) {
            case 'n':
                s[j] = '\n';
                break;
            case 't':
                s[j] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j] = t[i];
                break;
            }
            break;
        default:
            s[j] = t[i];
            break;
        }
        ++j;
    }
    s[j] = '\0';
}
