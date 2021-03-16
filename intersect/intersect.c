#include <stdio.h>
#include <stdlib.h>
/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int*
        returnSize) {

    int *new;

    new = malloc(5 * sizeof(int));

    return(new);
}

static void
printarrs(int *a, int a_len, int *b, int b_len)
{

    printf("a: ");
    for (int i = 0; i < a_len; i++) {
        printf("%d ", a[i]);
    }
    printf("\nb: ");
    for (int i = 0; i < b_len; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
int
main(int argc, char *argv[])
{
    int *nums1;
    int *nums2;
    int x;
    int y;

    x = 10;
    y = 3;

    nums1 = malloc(x * sizeof(int));
    nums2 = malloc(y * sizeof(int));

    for (int i = 0; i < x; i++) {
        nums1[i] = i;
    }
    for (int i = 0; i < y; i++) {
        nums2[i] = i + 5;
    }
    printarrs(nums1, x, nums2, y);
    return(0);
}
