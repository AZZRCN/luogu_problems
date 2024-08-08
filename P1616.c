#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
//已用空间 -> v
long long dp[10000001];
int main(){
    long long m,n;
    // cin >> m >> n;
    scanf("%lld %lld",&m,&n);
    dp[m] = 0;
    long long w,v;
    for(int i = 1; i <= n; i++){//考虑物品
        // cin >> w >> v;
        scanf("%lld %lld",&w,&v);
        //如果考虑,
        for(int j = w; j <= m; j++){//针对每种情况“递推”
            dp[j] = max(dp[j],dp[j-w]+v);
        }
    }
    // cout << dp[n][m];
    printf("%lld",dp[m]);
}