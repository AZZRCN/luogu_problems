#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int dp[101][101]={};
int main(){
    int n,m,maxn = 0,flag;
    // std::cin >> n >> m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&flag);
            if(flag){
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
            else{
                dp[i][j] = 0;
            }
            maxn = max(maxn,dp[i][j]);
        }

    }
    printf("%d",maxn);
}