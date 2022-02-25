/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
    integer x rotated to the right by n bit positions. */
#include <stdio.h>

unsigned rightrot(unsigned x, int n);

/* testing code */
main()
{
    printf("%x\n", rightrot(0x1f1f1f1f, 4));
    printf("%x\n", rightrot(0xffff1111, 8));
    printf("%x\n", rightrot(0x1, 4));
    return 0;
}

/* rightrot:  return x rotated to the right by n bit positions */
unsigned rightrot(unsigned x, int n)
{
    for (; n > 0; --n) {
        if ((x & 1U) == 1U)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = x >> 1;
    }
    return x;
}
