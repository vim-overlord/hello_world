/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate
    values from standard headers and by direct computation. Harder if you
    compute them: determine the ranges of the various floating-point types. */
#include <stdio.h>
#include <float.h>

main()
{
    unsigned long max;
    unsigned char c;
    unsigned i;
    unsigned short s;
    unsigned long l;
    double exponent;
    float f;
    double d;

    /* calculate limits of signed and unsigned char */
    c = 2;
    for (max = 1; max == c / 2; c = c * 2)
        max = c;
    printf("signed char: %d to %d\n", -max, max - 1);
    max = max + (max - 1);
    printf("unsigned char: 0 to %d\n", max);
    /* calculate limits of signed and unsigned int */
    i = 2;
    for (max = 1; max == i / 2; i = i * 2)
        max = i;
    printf("signed int: %d to %d\n", -max, max - 1);
    max = max + (max - 1);
    printf("unsigned int: 0 to %u\n", max);
    /* calculate limits of signed and unsigned short int */
    s = 2;
    for (max = 1; max == s / 2; s = s * 2)
        max = s;
    printf("signed short: %d to %d\n", -max, max - 1);
    max = max + (max - 1);
    printf("unsigned short: 0 to %u\n", max);
    /* calculate limits of signed and unsigned long int */
    l = 2;
    for (max = 1; max == l / 2; l = l * 2)
        max = l;
    printf("signed long: %ld to %ld\n", -max, max - 1);
    max = max + (max - 1);
    printf("unsigned long: 0 to %lu\n", max);
    /* calculate limits of float */
    f = 2.0;
    for (exponent = 1.0; exponent == f / 2.0; f = f * 2.0)
        exponent = f;
    printf("float: %g to %g\n", 1.0 / (exponent / 2.0), 2.0 * exponent);
    /* calculate limits of double */
    d = 2.0;
    for (exponent = 1.0; exponent == d / 2.0; d = d * 2.0)
        exponent = d;
    printf("double: %g to %g\n", 1.0 / (exponent / 2.0),
        1.999999999999999 * exponent);  /* a larger fraction rounds to Inf */   
}
