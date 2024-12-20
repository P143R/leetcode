#include <stdlib.h>
#include <stdio.h>

// Leetcode
int lengthOfLongestSubstring(char *right) {
    unsigned sequence[4] = {0, 0, 0, 0};
    int maxCount = 0;
    int count = 0;

    char *left = right;

    while (*right != '\0') {
        while (sequence[*right / 32] & (unsigned)1 << (*right % 32)) {
            sequence[*left / 32] ^= (unsigned)1 << (*left % 32);
            left++;
            count--;
        }

        sequence[*right / 32] ^= (unsigned)1 << (*right % 32);

        if (maxCount < ++count)
            maxCount = count;

        right++;
    }

    return maxCount;
}
// !Leetcode

int main() {
    
    printf("%d\n", lengthOfLongestSubstring((char *)"abcabcbb"));
    return 0;
}