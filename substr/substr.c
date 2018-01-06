#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int count[257] = { 0 };
    int maxlen = 0;
    int curlen = 0;
    int si = 0;

    /*
     * si is the number position (starting from one) where we are in our
     * string.  Since the array starts from zero (not 1) we need to subtract
     * one from the si to get the actual array offset.
     */
    for(si = 1; s[si - 1] != 0; si++) {
        int ci = (int)s[si - 1];
        // printf("%c si:%d  ci:%d count[%d]:%d curlen:%d maxlen:%d\n",
        //        s[si - 1], si, ci, ci, count[ci], curlen, maxlen);

        if (count[ci] == 0)  {
            /* First sighting of a character */
            curlen++;
        } else {
            /* We have seen this character before.  Adjust our current
             * count only if it's inside our current length.  If the last
             * time we saw this is outside the current string, then we can
             * keep counting up.
             */
            int last = si - count[ci];
            if (last <= curlen) {
                curlen = last;
            } else {
                curlen++;
            }
        }

        if (curlen > maxlen) {
            maxlen = curlen;
        }
        count[ci] = si;
    }
    return (maxlen);
}

int
main (int argc, char *argv[])
{
    int len = 0;

    if (argc < 1) {
        printf("Need substring as argv[1]\n");
        return (-1);
    }

    len = lengthOfLongestSubstring(argv[1]);

    printf("%d\n", len);

    return (0);
}
