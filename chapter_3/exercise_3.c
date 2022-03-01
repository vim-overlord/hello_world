/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
    notations like a-z in the string s1 into the equivalent complete list
    abc...xyz in s2. Allow for letters of either case and digits, and be
    prepared to handle cases like a-b-c and a-z0−9 and -a-z. Arrange that a
    leading or trailing - is taken literally. */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000    /* maximum output line size */

int my_getline(char s[], int lim);
void expand(char s1[], char s2[]);

/* testing code */
main()
{
    char s1[MAXLINE], s2[MAXLINE];

    while (my_getline(s1, MAXLINE) > 0) {
        expand(s1, s2);
        printf("%s", s2);
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

/* expand:  expand short hand notations in s1 into the equivalent list in s2 */
void expand(char s1[], char s2[])
{
    int c, i, j;

    i = j = 0;
    while (s1[i] != '\0') {
        if (s1[i+1] == '-' && (islower(s1[i]) && islower(s1[i+2]) ||
            isupper(s1[i]) && isupper(s1[i+2]) || isdigit(s1[i]) &&
            isdigit(s1[i+2])) && s1[i] < s1[i+2]) {
            c = s1[i];
            while (c <= s1[i+2]) {
                s2[j++] = c;
                ++c;
            }
            i += 3;
        } else
            s2[j++] = s1[i++];
    }
    s2[j] = '\0';
}
