#include <stdio.h>
#include <string.h>

/* Changes s in place. max string size is largest int, otherwise overflow */
char* reverseString(char* s) {
	int start = 0;
	int end = (int)strlen(s) - 1;
    char t;

    if (end <= 0) {
        return (s);
    }

	while (start < end) {
		t = s[start];
		s[start++] = s[end];
		s[end--] = t;
	}
	return (s);
}

int
main (int argc, char *argv[])
{
    char empty[] = "";
    char *s = empty;

    if (argc == 2) {
        s = argv[1];
        s = reverseString(s);
        printf("Result: %s\n", s);
    } else {
        /* Hacky test list. */
        char a[] = "a";
        char ab[] = "ab";
        char abc[] = "abc";
        char abcd[] = "abcd";
        s = reverseString(s);
        printf("Result: %s\n", s);
        s = a;
        s = reverseString(s);
        printf("Result: %s\n", s);
        s = ab;
        s = reverseString(s);
        printf("Result: %s\n", s);
        s = abc;
        s = reverseString(s);
        printf("Result: %s\n", s);
        s = abcd;
        s = reverseString(s);
        printf("Result: %s\n", s);
    }

    return (0);
}
