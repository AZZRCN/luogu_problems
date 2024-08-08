#include <bits/stdc++.h>
using namespace std;
int dp[501][501];//最小花费[L][R]->[L,R]
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        dp[i][i]=1;
    }
    string str;
    cin >> str;
    str = "\0" + str;
    for(int i = 1; i <= n; i++){//elem the right point
        for(int j = 1; j < i; j++){
            
        }
    }
}