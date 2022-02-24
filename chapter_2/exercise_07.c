/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
    that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
    leaving the others unchanged. */
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

/* testing code */
main()
{
    printf("%x\n", invert(0xfe, 3, 4));
    printf("%x\n", invert(0x1001, 11, 8));
    printf("%x\n", invert(0x0, 23, 16));
    return 0;
}

/* invert:  return x with n bits starting from p inverted */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ ((~(~0U << n)) << (p + 1 - n));
}
