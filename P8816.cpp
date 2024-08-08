#include <bits/stdc++.h>
using namespace std;
pair<int,int>a[501];
int f[501][101];//点K,自由点数量j
int main(){
    memset(f,0,sizeof(f));
    int n,k,ans=-1;
    cin >> n >> k;
    int x,y;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1);
    //左下找
    for(int i = 1; i <= n; i++){//现在
        f[i][0]=1;
        for(int j = i-1; j>=1; j--){//往前推
            if(a[j].first > a[i].first || a[j].second > a[i].second){
                continue;
            }
            //计算点距
            int d = ((a[i].first-a[j].first)+(a[i].second-a[j].second)-1);//不算自己
            // cout << d << endl;
            for(int l=d; l <= k; l++){
                f[i][l]=max(f[j][l-x]+x+1,f[i][l]);//往左下,接上
                // ans = max(f[i][l],ans);
            }
        }
        for(int l = 0; l <= k; l++)ans = max(f[i][l],ans);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            ans = max(ans,f[i][j]+(k-j));
        }
    }
    cout << ans;
}
