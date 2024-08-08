#include <iostream>
#include <unordered_set>
#define int unsigned long long
using namespace std;
unordered_set<int> US;//不能说的
const int M = 10000000 + 1;
void init() {
	for (int i = 7; i <= M; i += 10) {
		if (US.find(i) != US.end())continue;
		for (int j = 1; i * j <= M; j++) {
			US.insert(i * j);
		}
	}
}
signed main() {
	init();
	int T, t, fort, it;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> t;
		if (US.find(t) != US.end()) {
			cout << -1 << endl;
		}
		else {
			fort = t + 1;
			while (US.find(fort) == US.end()) {
				fort++;
			}
			cout << fort << endl;
		}
	}
}