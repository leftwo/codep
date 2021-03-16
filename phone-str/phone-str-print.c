#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {

    int total_d;

    struct dinfo {
        char *substr;
        int ssi;
        int len;
        int mod_len;
    };
    struct dinfo *dinfo_arr;
    char **somestr = NULL;
    char *dtos[] = {
        "",
        "",
        "cab",
        "fde",
        "igh",
        "ljk",
        "omn",
        "rspq",
        "vtu",
        "yzwx"
    };

    *returnSize = 0;
    total_d = strlen(digits);
    if (total_d == 0) {
        return(NULL);
    }

    dinfo_arr = malloc(total_d * sizeof(struct dinfo));
    if (dinfo_arr == NULL) {
        return(NULL);
    }

    int tdlen = 1;
    int total = 1;
    int actual_d = 0;
    for (int i = 0; i < total_d; i++) {
         int di = (int)digits[i] - '0';
         if (di < 2) {
             continue;
         }
         printf("[%d] is %d dtos '%s'\n", i, di, dtos[di]);
         dinfo_arr[actual_d].substr = dtos[di];
         dinfo_arr[actual_d].ssi = 0;
         dinfo_arr[actual_d].len = strlen(dtos[di]);
         dinfo_arr[actual_d].mod_len = tdlen;
         tdlen = tdlen * dinfo_arr[actual_d].len;
         total = total * dinfo_arr[actual_d].len;
         actual_d++;
    }

    total_d = actual_d;
    for (int i = 0; i < total_d; i++) {
         printf("%s ssi:%d len:%d modlen:%d\n", dinfo_arr[i].substr,
             dinfo_arr[i].ssi, dinfo_arr[i].len, dinfo_arr[i].mod_len);
    }

    somestr = malloc(total * sizeof(char *));
    if (somestr == NULL) {
        return(NULL);
    }

    for (int i = 0; i < total; i++) {
        somestr[i] = malloc(total_d + 1);
        if (somestr[i] == NULL) {
            printf("Malloc failed for return string\n");
            return(NULL);
        }
        for (int j = 0; j < total_d; j++) {
            if (i % dinfo_arr[j].mod_len == 0) {
                dinfo_arr[j].ssi = (dinfo_arr[j].ssi + 1 )% dinfo_arr[j].len;
            }
            printf("%c", dinfo_arr[j].substr[dinfo_arr[j].ssi]);
            somestr[i][j] = dinfo_arr[j].substr[dinfo_arr[j].ssi];
        }
        somestr[i][total_d] = 0;
        printf(" ");
    }
    printf("\n");

    printf("Total:%d tdlen:%d\n", total, tdlen);

    *returnSize = total;
    free(dinfo_arr);
    return(somestr);
}

int
main (int argc, char *argv[])
{
    char **arr;
    char *str;
    int rs;

    if (argc < 1) {
        str = "234";
    } else {
        str = argv[1];
    }

    int total_d = strlen(str);
    for (int i = 0; i < total_d; i++) {
         int di = (int)str[i] - '0';
         if (di < 0 || di > 10) {
             printf("Illegal di value index %d value:%c\n", i, str[i]);
             return(-1);
         }
    }

    arr = letterCombinations(str, &rs);
    for (int i = 0; i < rs; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
    return(0);
}
