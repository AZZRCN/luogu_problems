#include <bits/stdc++.h>
using namespace std;
unordered_set<int> US;
int main(){
    int n,m,k,t;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> t;
        US.insert(t);
    }
    int ans = 0,nowpos;
    for(nowpos=0;nowpos<n;nowpos+=m){
        if(US.count(nowpos)){m++;}
        ans++;
    }
    cout << ans << endl;
}