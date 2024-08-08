#include <iostream>
#include <vector>
#include <unordered_map>
#define     
using namespace std;
vector<unsigned int> a,b,c;
static void read(unsigned int& n) {
    n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 0x9) {ch = getchar();}
	while ((ch ^ '0') < 0xA) {n = n * 0xA + ch - 0x30;ch = getchar();}
}
[[nodiscard]] unsigned long long gcd(unsigned long long _Mx, unsigned long long _Nx) noexcept /* strengthened */ {

    if (_Mx == 0U) {
        return static_cast<unsigned long long>(_Nx);
    }
    if (_Nx == 0U) {
        return static_cast<unsigned long long>(_Mx);
    }
    const unsigned long _Mx_trailing_zeroes = static_cast<unsigned long>(__builtin_ctzll(_Mx));
    unsigned long _Nx_trailing_zeroes = static_cast<unsigned long>(__builtin_ctzll(_Nx));
    const unsigned long _Common_factors_of_2 = (::std::min)(_Mx_trailing_zeroes, _Nx_trailing_zeroes);
    _Mx >>= _Mx_trailing_zeroes;
    for (;;) {
        _Nx >>= _Nx_trailing_zeroes;
        if (_Mx > _Nx) {
            unsigned long long _Temp = _Mx;
            _Mx = _Nx;
            _Nx = _Temp;
        }
        _Nx -= _Mx;
        if (_Nx == 0U) {
            return static_cast<unsigned long long>(_Mx << _Common_factors_of_2);
        }
        _Nx_trailing_zeroes = static_cast<unsigned long>(__builtin_ctzll(_Nx));
    }
}
int main(){
    cout << gcd(18,9);
}