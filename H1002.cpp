#include <iostream>
#include <algorithm>
using namespace std;
unsigned int a[1000001]={};
int main(){
    unsigned int n,ans=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n;i++){
        for(int j = i+1; j <= n; j++){
            ans = max(ans,a[i] ^ a[j]);
        }
    }
    cout << ans;
}