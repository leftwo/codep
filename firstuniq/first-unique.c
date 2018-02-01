#include <stdio.h>

/*
 * Problem statement indicated that strings would be all lower case letters
 * This brute force gave me 13ms Runtime.
 *
 * I think we might do better if we make a min-heap, but I'm not sure (as it
 * depends on the test cases) if it's faster to remove elements > 1, or just
 * keep incrementing their counts and let them stay in the tree.  Since we
 * know we will have 26 nodes max, we know how deep our tree will be.
 */
int firstUniqChar(char* s) {
    int offset[26] = { 0 };
    int count[26] = { 0 };
    int i = 0;
    int ai = 0;
    int min_i = -1;

    while (s[i] != '\0') {
        ai = (int)s[i] - 'a';
        // assert(ai < 26);
        count[ai]++;
        offset[ai] = i;
        i++;
    }
    for (i = 0; i < 26; i++) {
        if (count[i] == 1) {
            if (min_i == -1 || offset[i] < min_i) {
                min_i = offset[i];
            }
        }
    }
    return(min_i);
}

int
main(int argc, char *argv[])
{
    int res;

    if (argc > 1) {
        res = firstUniqChar(argv[1]);
    } else {
        res = firstUniqChar("abcdefgbcadg");
    }

    printf("Result: %d\n", res);
    return (res);
}

