#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
//前i个,剩余空间 -> w
int dp[101][1001];
int main(){
    int T,m;
    // cin >> T >> m;
    scanf("%d %d",&T,&m);
    dp[0][m] = 0;
    int w,v;
    for(int i = 1; i <= m; i++){//考虑物品
        // cin >> w >> v;
        scanf("%d %d",&w,&v);
        for(int j = T;j >=0; j--){//针对每种情况“递推”
            if(j >= w){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // cout << dp[m][T];
    printf("%d",dp[m][T]);
}