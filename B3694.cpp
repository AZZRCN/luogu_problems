#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int a[100001];
int b[100001];
unordered_map<int, int> MAP_;
int main() {
    int T, n, tot, temp = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
		//cout << "==============" << endl;
        cin >> n;
		MAP_.clear();
        temp = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            b[j] = a[j];
            //cout << "catch" << endl;
        }
        sort(b, b + n);
        tot = unique(b, b + n) - b;
		//cout << tot << endl;
        for (int j = 0; j < tot; j++) {
            temp++;
            MAP_.insert(make_pair(b[j], temp));
        }
        for (int j = 0; j < n; j++) {
            cout << MAP_[a[j]] << " ";
        }
        cout << endl;
    }
    system("pause");
}