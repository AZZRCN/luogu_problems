#include <iostream>
using namespace std;
short a[102][102];
short S[102][102]={};
int main(){
    int m,n,ans = -1,minn;
    bool flag = false;
    cin >> m >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
            bool flag = true;
            cin >> a[i][j];
            S[i][j] = S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
            minn=1;
            //从S[i][j]开始直到S[i-t][j-t](i == t || j == t)
            for(int t = 1; t < min(i,j); t++){
                if(S[i][j]-S[i-t-1][j]-S[i][j-t-1]+S[i-t-1][j-t-1]==(t+1)*(t+1)){
                    minn++;
                }
                else{
                    break;
                }
            }
            ans = max(minn,ans);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << S[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans+1;

}