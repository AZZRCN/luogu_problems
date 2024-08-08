#include <bits/stdc++.h>
using namespace std;
stack<int> deepth;
//[1] < [2] < [3]
int main(){
    //not P3467
    int n,w,ans=0,t;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w;
        while(not deepth.empty() && w < deepth.top()){
            ans += deepth.top() - w;
            while(not deepth.empty() && w < deepth.top()){
                deepth.pop();
            }
        }
        if(not deepth.empty() && w == deepth.top()){
            continue;
        }
        deepth.push(w);
    }
    cout << ans+ deepth.top() << endl;
}