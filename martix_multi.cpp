#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b)? (a) : (b))
#define base 1000000000
using namespace std;
template <unsigned long long rows, unsigned long long cols>
class martix{
    public:
    unsigned long long a[rows + 1][cols + 1];
    void init(){memset(a, 0, sizeof(a));}
    inline unsigned long long *operator[](const unsigned long long &p){return a[p];}
    template <unsigned long long rows2, unsigned long long cols2>
    martix<rows, cols2> operator*(martix<rows2, cols2> &O){
        martix<rows, cols2> m;
        m.init();
        for (unsigned long long i = 1; i <= rows; i++){
            for (unsigned long long j = 1; j <= cols2; j++){
                for (unsigned long long k = 1; k <= cols; k++){
                    m[i][j] += (a[i][k] * O[k][j]);
                }
            }
        }
        return m;
    }
};
int dec_len(int n){
    int len = 0;
    while (n){
        len++;
        n /= 10;
    }
    return max(1, len);
}
int main(){
    long long n, m,lm,ln,cur,ans=0;
    martix<500, 1> m1;martix<500, 10> m2;
    m1.init();m2.init();
    scanf("%lld %lld",&n,&m);
    ln = dec_len(n), lm = dec_len(m),cur = ln;
    while (n){
        m1[cur][1] = n % 10;n /= 10;cur--;
    }
    cur = lm;
    while (m){
        m2[1][cur] = m % 10;m /= 10;cur--;
    }
    martix<10, 10> m3 = m1 * m2;
    for (int i = ln; i >= 1; i--){
        for (int j = lm; j >= 1; j--){
            ans+=((int)pow(10,ln+lm-i-j))*m3[i][j];
        }
    }
    printf("%lld",ans);
}