#include <deque>
#include <iostream>
using namespace std;
deque<int> q;
void bininsert(int n) {
    q.insert(lower_bound(q.begin(),q.end(),n), n);
}
int main() {
    int n, w, t;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        bininsert(t);
        cout << *(q.end()-1 - (
            max(
                ((int)q.size() * w / 100) - 1
            ,0))) << " ";
    }
    system("pause");
}