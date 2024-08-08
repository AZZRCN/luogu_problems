#include <bits/stdc++.h>
long dp[1005][1005];
long least[1005];
long rleast[1005];
using namespace std;

int main(){
    memset(dp, 0x3f, sizeof(dp));
    memset(least,0x3f,sizeof(least));
    memset(rleast,0x3f,sizeof(rleast));
    long n,m;
    cin >> n >> m;
    long from,to,w;
    dp[1][1]=0;
    least[1]=0;
    rleast[1]=0;
    for(int i = 1; i <= m ; i++){
        cin >> from >> to >> w;
        dp[from][to]=min(dp[from][to],w);
    }
    //横纵遍历
    //i表示from,j表示to
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == 0x3f3f3f3f){
                cout << "-1\t";
            }
            else{
                cout << dp[i][j] << "\t";
            }
            if(dp[i][j] != 0x3f3f3f3f){
                least[j] = min(least[i] + dp[i][j],least[j]);
            };
            if(dp[j][j] != 0x3f3f3f3f){
                rleast[i]=min(rleast[i]+dp[j][i],rleast[j]);
            }
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++){
        cout << least[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << rleast[i] << " ";
    }
}