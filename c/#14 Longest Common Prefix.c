#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// Leetcode
char *longestCommonPrefix(char **strs, int strsSize) {
    char *res = *strs;

    while (*res != '\0') {
        for (int i = 1; i < strsSize; i++) {
            if (*res != *strs[i]) {
                *res = '\0';                
                return *strs;
            }

            strs[i]++;
        }
        
        res++;
    }

    return *strs;
}
// !Leetcode

int main() {
    char str1[] = "flower";
    char str2[] = "flow";
    char str3[] = "flight";
    char *s[] = {str1, str2, str3};

    char *lcp = longestCommonPrefix(s, 3);
    printf("%s\n", lcp);

    return 0;
}