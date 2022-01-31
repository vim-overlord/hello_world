/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
    use a function for conversion. */
#include <stdio.h>

float convert(float fahr);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    /* print Fahrenheit-Celsius table */
    fahr = lower;
    while (fahr <= upper) {
        celsius = convert(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

/* convert:  convert fahrenheit temperature to celsius */
float convert(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
