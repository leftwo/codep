#include <stdio.h>
static
int singleNumber(int* nums, int numsSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        x = x ^ nums[i];
    }
    return (x);
}
int
main(int argc, char *argv[])
{
    int x[11] = {7, 5, 2, 4, 6, 8, 5, 2, 4, 6, 8};
    int res = 0;

    res = singleNumber(x, 11);
    printf("Got:%d\n", res);
    return (0);
}
