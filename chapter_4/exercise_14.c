/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of
    type t. (Block structure will help.) */
#include <stdio.h>

/* swap:  swap two variables x and y of type t */
#define swap(t, x, y) \
    t z = x; \
    x = y; \
    y = z;

/* testing code */
main()
{
    int x = 0;
    int y = 1;
    
    swap(int, x, y);
    printf("%d %d\n", x, y);
    return 0;
}
