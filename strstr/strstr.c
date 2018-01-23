#include <stdio.h>

int strStr(char* haystack, char* needle) {
    int i = 0;
    int ni = 0;
    int start = 0;

    /* While not correct, it's what leetcode expects for NULL needle */
    if (needle[ni] == 0) {
        return(0);
    }
    while (haystack[i] != 0) {
        ni = 0;
        start = i;
        while (haystack[i++] == needle[ni++]) {
            if (needle[ni] == 0) {
                return (start);
            }
            if (haystack[i] == 0) {
                return (-1);
            }
        }
        i = start + 1;
    }
    return (-1);
}

int
main (int argc, char *argv[])
{
    int res;

    if (argc == 3) {
        res = strStr(argv[1], argv[2]);
    } else {
        res = strStr("hello", "ll");
    }

    printf("Result: %d\n", res);

    return (0);

}
