#include <stdio.h>

/*
 * Take an array of length N and rotate it by k to the right
 */
void
pa(int *a, int len, const char * desc)
{
    printf("%s [", desc);
    for (int i = 0; i < len; i++) {
        printf("%d, ", a[i]);
    }
    printf("]\n");
}

void rotate(int* nums, int numsSize, int k) {
    int shift_arr[k + 1];
    int i;

    if (numsSize <= 1) {
        return;
    }

    if (k % numsSize == 0 || (k >= numsSize && k % numsSize == k)) {
        return;
    }

    k = k % numsSize;

    for (i = 0; i < k + 1; i++) {
        shift_arr[i] = nums[i];
    }
    pa(shift_arr, k + 1, "shift:");
    pa(nums, numsSize, "nums: ");

    for (i = 0; i < numsSize; i++) {
        int shift = (k + i) % numsSize;
        int sai_to = (i + k) % (k + 1);
        int sai_from = i % (k + 1);
        shift_arr[sai_to] = nums[shift];
        nums[shift] = shift_arr[sai_from];

        // printf("i:%d  shift=%d  sai_from:%d  sai_to:%d\n",
        //         i, shift, sai_from, sai_to);
        // pa(shift_arr, k + 1, "shift:");
        // pa(nums, numsSize, "nums: ");
    }
}


int t1[] = {1, 2, 3, 4, 5, 6, 7};
int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int
main (int argc, char *argv[])
{
    int size = 15;
    int rot = 7;
    char msg[256];

    rotate(a1, size, rot);
    snprintf(msg, 256, "final %d -> %d", size, rot);
    pa(a1, size, msg);

    rotate(a1, 14, 7);
    pa(a1, 14, "final 14 7: ");
    rotate(a1, 15, 2);
    pa(a1, 14, "final 15 2: ");
    rotate(a1, 14, 2);
    pa(a1, 14, "final 14 2: ");

}
