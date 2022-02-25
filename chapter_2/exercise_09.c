/* Exercise 2-9. In a two’s complement number system, x &= (x−1) deletes the
    rightmost 1-bit in x. Explain why. Use this observation to write a faster
    version of bitcount. */
#include <stdio.h>

int bitcount(unsigned x);

/* testing code */
main()
{
    int x;

    for (x = 0x0; x <= 0xff; ++x)
        printf("%x: %d\n", x, bitcount(x));
    return 0;
}

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}
