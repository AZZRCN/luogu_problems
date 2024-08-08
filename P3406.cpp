#include <iostream>
using namespace std;
int go_times_delta[100001] = {};
int main() {
    long long n, m, a, b, c, carry = 0, ans = 0;
    cin >> n >> m;
    cin >> b;
    for (int i = 1; i < m; i++) {
        a = b;
        cin >> b;
        go_times_delta[min(a, b)]++; go_times_delta[max(a, b)]--;
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        carry += go_times_delta[i];
        if (carry == 0) {
            continue;
        }
        if (carry * a <= carry * b + c) {
            ans += carry * a;
        }
        else {
            ans += carry * b + c;
        }
    }
    cout << ans;
    system("pause");
}