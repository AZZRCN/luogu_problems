#include <iostream>
using namespace std;
unsigned long long S[1001][1001] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("E:\\CT\\out", "w", stdout);
    unsigned long long ans = 0;
    unsigned long long T, n, m, t, q, u=0, v=0, x=0, y=0;
    cin >> T;
    // T = 5;
    while (T--) {
        ans = 0;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> t;
                S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + t;
            }
        }
        for (int i = 1; i <= q; i++) {
            cin >> u >> v >> x >> y;
            ans ^= (S[x][y] - S[x][v-1] - S[u-1][y] + S[u-1][v-1]);
        }
        cout << ans << endl;
    }
}