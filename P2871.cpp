#include <bits/stdc++.h>
using namespace std;
int f[12881];//前i个物品，容量为j的总价值
int v[3403];//价值
int w[3403];//占用空间大小
int main(){
    int N,W;
    cin >> N >> W;
    for(int i = 1; i <= N; i++){
        cin >>w[i]>>v[i];
        for(int j = W; j >= w[i]; j--){
            f[j] = max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout << f[W];
}