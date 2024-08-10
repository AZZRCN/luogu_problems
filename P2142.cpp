#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
template<long long rows, long long cols>
struct martix {
    long long a[rows + 1][cols + 1];
    void init() {
        memset(a, 0, sizeof(a));
    }
    inline long long* operator[](const long long& p) {
        return a[p];
    }
    martix<rows, cols> operator+(martix<rows, cols> O) {
        martix<rows, cols> ret;
        ret.init();
        for (long long i = 1; i <= rows; i++) {
            for (long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] + O[i][j];
            }
        }
        return ret;
    }
    martix<rows, cols> operator-(martix<rows, cols> O){
        martix<rows, cols> ret;
        ret.init();
        for (long long i = 1; i <= rows; i++) {
            for (long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] - O[i][j];
            }
        }
        return ret;
    }
    bool operator>(martix<rows,cols> O) {//同级，慎用
        for (long long i = 1; i <= rows; i++) {
            for (long long j = 1; j <= cols; j++) {
                if (a[i][j] > O[i][j])return true;
                if (a[i][j] < O[i][j])return false;
            }
        }
        return false;
    }
    
    bool operator>=(martix<rows,cols> O) {//同级，慎用
        for (long long i = 1; i <= rows; i++) {
            for (long long j = 1; j <= cols; j++) {
                if (a[i][j] > O[i][j])return true;
                if (a[i][j] < O[i][j])return false;
            }
        }
        return true;
    }
};
string a,b;
int main(){
    martix<1,10086> m_a,m_b,ret;
    m_a.init();m_b.init();ret.init();
    cin >> a >> b;
    if((a.size() == b.size() && a < b) || (a.size() < b.size())){
        swap(a,b);
        printf("-");
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i = 0 ; i < a.length(); i++){
        m_a[1][i+1] = a[i] - '0';
    }
    for(int i = 0 ; i < b.length(); i++){
        m_b[1][i+1] = b[i] - '0';
    }
    ret = m_a - m_b;
    //fix part
    int carry = 0;
    for(int i = 1; i <= 10086; i++){
        if(ret[1][i] < 0){
            ret[1][i] += 10;
            ret[1][i+1]--;
        }
    }
    int i = 10086;
    while(i && ret[1][i] == 0){i--;}
    if(i ==0){
        cout << "0";
        return 0;
    }
    for(;i>=1 ;i--){
        cout << ret[1][i];
    }
    exit(0);
}