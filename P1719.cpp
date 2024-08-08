#include <iostream>
using namespace std;
int num[121][121]={};
int S[121][121]={};
int dp[121]={};
int maxn = 0x80000000;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> num[i][j];
            S[i][j]=S[i][j-1]+num[i][j];
        }
    }
    for(int x1 = 1; x1 <= n; x1++){
        for(int x2 = x1; x2 <= n; x2++){
            for(int i = 1; i <= n; i++){
                dp[i] = max(S[i][x2]-S[i][x1-1],dp[i-1]+S[i][x2]-S[i][x1-1]);
                maxn = max(maxn,dp[i]);
            }
        }
    }
    cout << maxn << endl;
}