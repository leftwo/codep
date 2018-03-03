#include <stdio.h>
/*
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums
 * should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

static
void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    int zero = 0;

    while (zero < numsSize) {
        while (i < numsSize && nums[i] == 0) {
            i++;
        }

        if (i >= numsSize) {
            nums[zero] = 0;
            zero++;
        } else if (nums[i] != 0) {
            if (i != zero) {
                nums[zero] = nums[i];
            }
            i++;
            zero++;
        }
    }
}

int
main (int argc, char *argv[])
{

    int nums[] = {1, 2, 3, 0, 4, 5};
    int n2[] = {0};

    int n2_size = 1;
    int nums_size = 6;

    moveZeroes(nums, nums_size);
    moveZeroes(n2, n2_size);

    for (int i = 0; i < nums_size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    for (int i = 0; i < n2_size; i++) {
        printf("%d ", n2[i]);
    }
}
