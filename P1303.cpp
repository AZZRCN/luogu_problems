#include <stdio.h>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b)? (a) : (b))
#define base 1000000000
using namespace std;
template < long long rows,  long long cols>
class martix{
    public:
     long long a[rows + 1][cols + 1];
    void init(){memset(a, 0, sizeof(a));}
    inline  long long *operator[](const  long long &p){return a[p];}
    template < long long rows2,  long long cols2>
    martix<rows, cols2> operator*(martix<rows2, cols2> &O){
        martix<rows, cols2> m;
        m.init();
        for ( long long i = 1; i <= rows; i++){
            for ( long long j = 1; j <= cols2; j++){
                for ( long long k = 1; k <= cols; k++){
                    m[i][j] += (a[i][k] * O[k][j]);
                }
            }
        }
        return m;
    }
};
 long long ans[1001];
int main(){
    long long lm,ln,cnt,cur=0;
    martix<500, 1> m1;martix<1, 500> m2;
    string n,m;
    m1.init();m2.init();
    cin >> n >> m;
    ln = n.length(), lm = m.length();
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
    memset(ans, 0, sizeof(ans));
    for( long long i =n.size()-1; i >= 0;i --){
        m1[500-(i/4)][1] = m1[500-(i/4)][1] * 10 + n[i] - '0';
    }
    for( long long i =m.size()-1; i >= 0;i --){
        m2[1][500-(i/4) ] = m2[1][500-(i/4) ] * 10 + m[i] - '0';
    }
    martix<500, 500> m3 = m1 * m2;
    for ( long long i = 500; i >= 1; i--){
        for ( long long j = 500; j >= 1; j--){
            ans[i+j]+=m3[i][j];
        }
    }
     long long carry = 0;
    for( long long i = 1000; i >= 1; i--){
        carry += ans[i];
        ans[i] = carry%10000;
        carry /= 10000;
    }
     long long i;
    for(i = 1; i <= 1000; i++){
        if(ans[i]) break;
    }
    if(i == 1001){cout << "0";return 0;}
    cout << ans[i];
    for(i++;i<= 1000; i++){
        printf("%04d",ans[i]);
    }
}