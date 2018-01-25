#include <stdio.h>
#include <stdlib.h>

/* We don't deal with integer overflow */
int
anp(int x, int y)
{
    int carry;
    if (x == 0)
        return(y);

    while (y != 0) {
        carry = x & y;
        x ^= y;
        y = carry << 1;
    }
    return(x);
}
int
main(int argc, char *argv[])
{
    int x = 0x7fffffff;
    int y = 0x7fffffff;
    int res;

    if (argc == 3) {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    printf("x:%x y:%x\n", x, y);
    res = anp(x, y);


    if (res != x + y) {
        printf("Error, mismatch ");
    }
    printf("res:%d %d\n", res, x + y);
    return(0);
}
