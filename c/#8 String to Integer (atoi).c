#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Leetcode
#define MAX INT_MAX / 10

int myAtoi(char *s) {
    while (isspace(*s))
        s++;

    int negative = 1;

    if (*s == '-') {
        negative = -1;
        s++;
    } else if (*s == '+')
        s++;

    if (!isdigit(*s))
        return 0;

    int res = *(s++) - '0';

    while (isdigit(*s)) {
        int digit = (*s - '0') * negative;

        if (res > MAX ||
                (res == MAX && (digit <= -8 || digit >= 7)))
            return negative == -1 ? INT_MIN : INT_MAX;

        res *= 10;
        res += *(s++) - '0';
    }

    return res * negative;
}
// !Leetcode

int main() { return 0; }
