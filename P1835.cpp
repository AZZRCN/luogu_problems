#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;
unsigned int L, R, ans = 0;
#define ull unsigned int
#define r(...) return __VA_ARGS__
std::vector<unsigned int> pri;
unordered_set<int> not_prime;
void fillPrism(const unsigned int& N) {
	not_prime.insert(4);
	not_prime.insert(6);
	not_prime.insert(8);
	not_prime.insert(9);
	pri.push_back(2);
	pri.push_back(3);
	for (unsigned int i = 6; i <= N; i += 6) {
		if (!not_prime.count(i - 1)) {
			pri.push_back(i - 1);
		}
		for (unsigned int j : pri) {
			if (((i - 1) * j > N)) { break; }
			not_prime.insert((i - 1) * j);
			if (((i - 1) % j == 0)) { break; }
		}
		if (!not_prime.count(i + 1)) {
			pri.push_back(i + 1);
		}
		if (i + 1 > N) { break; }
		for (unsigned int j : pri) {
			if (((i + 1) * j > N)) { break; }
			not_prime.insert((i + 1) * j);
			if (((i + 1) % j == 0)) { break; }
		}
	}
}
bool isPrime(const ull& n) {
	if (n < 2 || ((n > 2) && ((n & 1) == 0))) r(false);
	const int sqrt_ = (int)floor(sqrt(n));
	for (unsigned int index = 0; pri[index] <= sqrt_; index++) {//i is index
		if (n % pri[index] == 0) {
			r(false);
		}
	}
	r(true);
}
int main() {
	cin >> L >> R;
	fillPrism(50000);//筛出素数
	//L = 1;
	//R = 100;
	for (int i = L; i <= R; i++) {
		if (isPrime(i))ans++;
	}
	cout << ans;

	system("pause");
}