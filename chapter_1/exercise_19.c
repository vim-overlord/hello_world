/* Exercise 1-19. Write a function reverse(s) that reverses the character
    string s. Use it to write a program that reverses its input a line at a
    time. */
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int my_getline(char line[], int maxline);
void reverse(char s[]);

/* testing code */
main()
{
    char line[MAXLINE]; /* current input line */

    while (my_getline(line, MAXLINE) > 0) {
        reverse(line);
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

/* reverse:  reverse character string s */
void reverse(char s[])
{
    int i, len, temp;
    
    for (len = 0; s[len] != '\0'; ++len)
        ;
    --len;  /* exclude \0 */
    for (i = 0; i < len; ++i) {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
        --len;
    }
}
