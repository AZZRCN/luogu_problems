#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "..\..\VSOT\console\main.cpp"
using namespace std;
bool cmp(const string& a, const string& b) {
	return a + b > b + a;
}
int main() {
	vector<string> V;
	string s;
	int n,t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		V.push_back(to_string(t));
	}
	sort(V.begin(), V.end(), cmp);
	for (auto k : V) {
		cout << k;
	}
#ifdef C_pause
	C_pause;
#endif
}