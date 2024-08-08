#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long> pri;
void fillPrism(unsigned long long N) {
    std::vector<bool> not_prime(N + 1, false);
    pri.push_back(2);
    not_prime[4] = true;
    for (unsigned long long i = 3; i <= N; i += 2) {
        if (!not_prime[i]) {
            pri.push_back(i);
        }
        for (unsigned long long j : pri) {
            if ((i * j > N)) { break; }
            not_prime[i * j] = true;
            if (i % j == 0) { break; }
        }
    }
}
int main() {
    fillPrism(100000000); // 修改这里，传递一个整数类型的上限值
    unsigned long long n, q;
    cin >> n >> q;
    for (unsigned long long i = 1; i <= q; i++) {
        cin >> n;
        cout << pri[n - 1] << endl;
    }
}