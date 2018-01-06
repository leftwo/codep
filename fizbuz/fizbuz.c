#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **str;
    int si = 0;

    str = malloc(n * sizeof(char*));
    for (int i = 1; i <= n; i++) {
        str[si] = malloc(9);
        if (i % 15 == 0) {
            strncat(str[si], "FizzBuzz", 8);
        } else if (i % 3 == 0) {
            strncat(str[si], "Fizz", 4);
        } else if (i % 5 == 0) {
            strncat(str[si], "Buzz", 4);
        } else {
            snprintf(str[si], 9, "%d", i);
        }
        si++;
    }

    *returnSize = n * 9;
    return (str);
}

int
main (int argc, char *argv[])
{
    int n = 1;
    int size = 0;
    char **str;

    if (argc > 1)
        n = atoi(argv[1]);

    str = fizzBuzz(n, &size);

    printf("size:%d\n", size);
    for (int i = 0; i < n; i++) {
        printf("[%d] %s\n", i, str[i]);
    }

    return 0;
}
