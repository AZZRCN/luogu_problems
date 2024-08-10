#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
static unsigned long long mod = 1e9 + 7;
static void ADD(unsigned long long& x, const unsigned long long& y) {
    x += y;
    if (x >= mod)x -= mod;
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
    template<unsigned long long rows2, unsigned long long cols2>
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
        martix<rows, cols>_copy = *this;
        martix<rows, cols> ret;
        ret.init();
        ret[1][1] = ret[2][2] = 1;
        for (; pow_time; (_copy = _copy * _copy)) {
            if (pow_time & 1)ret = ret * _copy;
            (pow_time >>= 1);
        }
        return ret;
    }
    martix<rows, cols> operator+(martix<rows, cols> O) {
        martix<rows, cols> ret;
        ret.init();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] + O[i][j];
            }
        }
        return ret;
    }
    martix<rows, cols> operator-(martix<rows, cols> O){
        martix<rows, cols> ret;
        ret.init();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] - O[i][j];
            }
        }
        return ret;
    }
    bool operator>(martix<rows,cols> O) {//同级，慎用
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                if (a[i][j] > O[i][j])return true;
                if (a[i][j] < O[i][j])return false;
            }
        }
        return false;
    }
    
    bool operator>=(martix<rows,cols> O) {//同级，慎用
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                if (a[i][j] > O[i][j])return true;
                if (a[i][j] < O[i][j])return false;
            }
        }
        return true;
    }
    martix<rows,cols> push_left(unsigned long long O){
        martix<rows,cols> ret;
        ret.init();
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                ret[i][max(j-O,1ULL)] = a[i][j];
            }
        }
        return ret;
    }
    martix<rows,cols> push_right(unsigned long long O){
        martix<rows,cols> ret;
        ret.init();
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                ret[i][min(j+O,cols)] = a[i][j];
            }
        }
        return ret;
    }
    martix<rows,cols> push_to_left(){
        int flag = 0;
        for(int j = 1; j <= cols; j++){
            for(int i = 1; i <= rows; i++){
                if(a[i][j]){
                    return push_left(j-1);
                }
            }
        }
        martix<rows,cols> ret;
        ret.init();
        return ret;
    }
};
int a[5001];
int D[5001];
int main(){
    unsigned long long di;
    memset(a,0,sizeof(a));
    memset(D,0,sizeof(D));
    string str;
    cin >> str;
    cin >> di ;
    reverse(str.begin(),str.end());
    for(int i = 0 ; i < str.length(); i++){
        D[5000-i] = str[i]-'0';
    }
    unsigned long long carry = 0;
    for(int i = 1; i <= 5000; i++){
        carry = carry*10 + D[i];
        a[i] = carry / di;
        carry %= di;
    }
    int i = 1;
    for(; i <= 5000; i++){
        if(a[i])break;
    }
    if(i == 5001){
        cout << "0";
        return 0;
    }
    for(; i <= 5000; i++){
        cout << a[i];
    }
}