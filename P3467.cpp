#include <bits/stdc++.h>
using namespace std;
stack<int> deepth;
//[1] < [2] < [3]
int main(){
    //not P3467
    int n,w,d,ans=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d >> w;
        while(not deepth.empty() && w < deepth.top()){
            deepth.pop();
            ans++;
        }
        if(not deepth.empty() && w == deepth.top()){
            continue;
        }
        deepth.push(w);
    }
    cout << ans+ deepth.size() << endl;
    
}