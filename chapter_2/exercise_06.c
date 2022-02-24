/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
    bits that begin at position p set to the rightmost n bits of y, leaving the
    other bits unchanged. */
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

/* testing code */
main()
{
    printf("%x\n", setbits(0xff, 3, 4, 0x1));
    printf("%x\n", setbits(0x1111, 11, 8, 0xff));
    printf("%x\n", setbits(0x0, 23, 16, 0xffff));
    return 0;
}

/* setbits:  return x with rightmost n bits from y starting from p */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0U << n) << (p+1-n))) | ((y & ~(~0U << n)) << (p+1-n));
}
