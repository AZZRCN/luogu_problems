#include <stdio.h>
#include <limits.h>

int main() {
    int maxn = INT_MIN, flast = 0, fnow, for_in, n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &for_in);
        fnow = (flast + for_in) > for_in? (flast + for_in) : for_in;
        flast = fnow;
        if (fnow > maxn) {
            maxn = fnow;
        }
    }
    printf("%d", maxn);
    return 0;
}