/* Exercise 1-24. Write a program to check a C program for rudimentary syntax
    errors like unbalanced parentheses, brackets and braces. Don’t forget about
    quotes, both single and double, escape sequences, and comments. (This
    program is hard if you do it in full generality.) */
#include <stdio.h>

#define YES 1
#define NO 0

int read_block(int end);
int read_str(char quote);
int read_cmt(void);

main()
{
    int valid;  /* whether the C program is valid or not */

    if ((valid = read_block(EOF)) == NO)
        printf("syntax error!\n");
    return 0;
}

/* read_block:  reads a block until its closing sequence or EOF is reached;
    returns YES block is valid, NO if block is invalid */
int read_block(int end)
{
    int c;
    int valid;  /* whether current block is valid */

    valid = YES;
    while ((c = getchar()) != EOF && valid == YES) {
        if (c == '/') {
            c = getchar();
            if (c == '*')
                if ((valid = read_cmt()) == YES)
                    c = getchar();
        }
        if (c == end)
            return YES;
        /* check for closing braces without a corresponding opening brace */
        else if (c == ')' || c == ']' || c == '}')
            return NO;
        else if (c == '(')
            valid = read_block(')');
        else if (c == '[')
            valid = read_block(']');
        else if (c == '{')
            valid = read_block('}');
        else if (c == '\'')
            valid = read_str('\'');
        else if (c == '"')
            valid = read_str('"');
    }
    if (c != EOF)
        return NO;
    else
        return valid;
}

/* read_str:  reads a quoted string and returns YES if it terminates */
int read_str(char quote)
{
    int c;

    while ((c = getchar()) != EOF) {        
        if (c == quote)
            return YES;
        /* ignore second character in escape sequence */
        if (c == '\\')
            getchar();
    }
    return NO; /* end quote missing */
}

/* read_cmt:  reads a comment and returns YES if it terminates */
int read_cmt(void)
{
    int c;

    while ((c = getchar()) != EOF)  
        if (c == '*')
            if ((c = getchar()) == '/')
                return YES;
    return NO; /* comment never terminates */
}
