#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q[80];
int main() {
    int m, n,t;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            q[i].push(t);
        }
    }
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt = 0;
        while(not q[i].empty()) {
            cnt++;
            ans += (q[i].top() << cnt);
            printf("%d",q[i].top());
            q[i].pop();
        }
        printf("\n");
    }
    cout << ans << endl;
}