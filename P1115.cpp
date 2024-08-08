#include <iostream>
static void read(int& n) {
	signed char w = 0;
	n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 9) {
		if (not (ch ^ '-')) w = 1;
		ch = getchar();
	}
	while ((ch ^ '0') < 0xA) {
		//n = n * 10 + (ch ^ '0');
		n = n * 0xA + ch - 0x30;
		ch = getchar();
	}
	if (w) {
		//n--;
		//n ^= 0xFFFFFFFF;
		n = -n;
	}
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int maxn = -0x7fffffff - 1, flast = 0, fnow, for_in, n;
    // scanf("%d", &n);
    read(n);
    while (n--) {
        // scanf("%d", &for_in);
        read(for_in);
        fnow = (flast + for_in) > for_in? (flast + for_in) : for_in;
        flast = fnow;
        if (fnow > maxn) {
            maxn = fnow;
        }
    }
    // printf("%d", maxn);
    std::cout << maxn;
    return 0;
}