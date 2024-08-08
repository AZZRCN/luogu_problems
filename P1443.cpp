#include <bits/stdc++.h>
using namespace std;
#define u unsigned
#define ll long long
ll dp[401][401]={},trust=0;
bool Vis[401][401]={};
u maxx,maxy;
//f(x) = dp[x][y] = min(dp[x][y], times)
void slove(int x, int y,ll times){
    if(times >= dp[x][y]){
        return;
    }
    dp[x][y] = min(dp[x][y], times);
    trust = max(trust, dp[x][y]);
    //马的移动
    if(x + 2 <= maxx && y + 1 <= maxy){
        slove(x + 2, y + 1,times+1);
    }
    if(x + 2 <= maxx && y - 1 >= 1){
        slove(x + 2, y - 1,times+1);
    }
    if(x + 1 <= maxx && y + 2 <= maxy){
        slove(x + 1, y + 2,times+1);
    }
    if(x + 1 <= maxx && y - 2 >= 1){
        slove(x + 1, y - 2,times+1);
    }
    if(x - 1 >= 1 && y + 2 <= maxy){
        slove(x - 1, y + 2,times+1);
    }
    if(x - 1 >= 1 && y - 2 >= 1){
        slove(x - 1, y - 2,times+1);
    }
    if(x - 2 >= 1 && y + 1 <= maxy){
        slove(x - 2, y + 1,times+1);
    }
    if(x - 2 >= 1 && y - 1 >= 1){
        slove(x - 2, y - 1,times+1);
    }
}
int main(){
    // freopen("in","r",stdin);
    memset(dp,0x3f,sizeof(dp));
    int t1,t2;
    dp[1][1]=1;
    cin >> maxx >> maxy >> t1 >> t2;
    
    slove(t1,t2,0);
    for(int i = 1; i <= maxx; i++){
        for(int j = 1; j <= maxy; j++){
            if(dp[i][j] > trust){
                cout << "-1 ";
            }
            else
            {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
}