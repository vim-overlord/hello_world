/* Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
    rather than calling alloc to maintain storage. How much faster is the
    program? */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
#define BUFSIZE 10000

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *buf, int bufsize);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
    char buf[BUFSIZE];  /* buffer for inputted characters */
    int nlines;         /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES, buf, BUFSIZE)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int my_getline(char *, int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines, char *buf, int bufsize)
{
    int len, nlines;
    char *p;

    nlines = 0;
    p = buf;
    while ((len = my_getline(p, bufsize - (p - buf))) > 0)
        if (nlines >= maxlines)
            return -1;
        else {
            p[len-1] = '\0';    /* delete newline */
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* getline:  get line into s, return length */
int my_getline(char *s, int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(char *v[],  int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)   /* do nothing if array contains */
        return;           /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v,  ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap:  interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
