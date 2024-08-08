#include <iostream>
#include <cstring>
using namespace std;
static unsigned long long mod = 1e9 + 7;
static void ADD(unsigned long long& x, const unsigned long long& y) {
    x += y;
    if (x>= mod)x -= mod;
}
template<unsigned long long rows, unsigned long long cols>
struct martix {
    unsigned long long a[rows + 1][cols + 1];
    void init() {
        memset(a, 0, sizeof(a));
    }
    inline void clear() { init(); }
    inline unsigned long long* operator[](const unsigned long long& p) {
        return a[p];
    }
    template<unsigned long long rows2,unsigned long long cols2>
    martix<rows, cols2> operator*(martix<rows2, cols2>& O) {
        martix<rows, cols2> m;
        m.clear();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols2; j++) {
                for (unsigned long long k = 1; k <= cols; k++) {
                    ADD(m[i][j], (a[i][k] * O[k][j]) % mod);
                }
            }
        }
        return m;
    }
    martix<rows, cols> operator^(long long pow_time) {
        martix<rows, cols>_copy=*this;
        martix<rows, cols> ret;
        ret.init();
        ret[1][1] = ret[2][2] = 1;
        for (; pow_time; (_copy = _copy*_copy)) {
            if (pow_time & 1)ret = ret * _copy;
            (pow_time >>= 1);
        }
        return ret;
    }
};
int main() {
    long long y;
    cin >> y;
    martix<2, 2> a;
    a.init();
    a[1][1] = a[1][2] = a[2][1] = 1;
    a = a ^ y;
    cout << a[1][2]%mod << '\n';
    system("pause");
}