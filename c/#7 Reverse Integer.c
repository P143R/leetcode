#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX INT_MAX / 10

int reverse(int x) {
        int negative = x < 0 ? -1 : 1;

        int res = 0;

        while(x != 0) {
            int digit = x % 10;
            if  (res > MAX ||
                    (res == MAX / 10 && (digit <= -8 || digit >= 7))) {
                return 0;
            }

            res = res * 10 +  digit * negative;
            x /= 10;
        }

        return res * negative;
}

int main() {
	assert(reverse(123) == 321);
	assert(reverse(-123) == -321);
	assert(reverse(120) == 21);
	assert(reverse(INT_MAX) == 0);
	assert(reverse(1111111113) == 0);

	return 0;
}
