#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
template<unsigned long long rows, unsigned long long cols>
struct martix {
    unsigned long long a[rows + 1][cols + 1];
    void init() {
        memset(a, 0, sizeof(a));
    }
    inline unsigned long long* operator[](const unsigned long long& p) {
        return a[p];
    }
    martix<rows, cols> operator+(martix<rows, cols> O) {
        martix<rows, cols> ret;
        ret.init();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                ret[1][i][j] = a[1][i][j] + O[1][i][j];
            }
        }
        return ret;
    }
};
int main(){
    martix<1,500> ans;
    ans.init();
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.length(); i++){
        ans[1][i] += str[i]-'0';
    }
    cin >> str;
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.length(); i++){
        ans[1][i] += str[i]-'0';
    }
    int carry = 0;
    for(int i = 0; i <= 500; i++){
        carry = ans[1][i] + carry;
        ans[1][i] = carry % 10;
        carry /= 10;
    }
    int i = 500;
    for(; i >= 0; i--){
        if(ans[1][i]) break;
    }
    if(i == -1){
        cout << "0";
        return 0;
    }
    for(; i >= 0; i--){
        cout << ans[1][i];
    }
}