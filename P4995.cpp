#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
list<int> L;
int main(){
    int n,t,last = 0;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> t;
        L.push_back(t);
    }
    L.sort();
    bool flag = true;
    while(not L.empty()){
        if(flag){
            ans += (L.back()-last) * (L.back() - last);
            last = L.back();
            L.pop_back();
        }
        else{
            ans += (L.front()-last) * (L.front() - last);
            last = L.front();
            L.pop_front();
        }
        flag = !flag;
        
    }
    cout << ans;
}