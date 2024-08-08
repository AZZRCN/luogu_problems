#include <set>
#include <iostream>
#include <vector>
using namespace std;
set<int> S;
int main(){
    vector<int> v;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int t,maxn=-1;
    for(int i = 1; i <= n; i++){
        cin >> t;
        maxn = max(maxn,t);
        v.push_back(t);
    }
    vector<int>::iterator i=v.begin(),j;
    for(;i!=v.end();i++){
        S.insert((*i)%maxn);
        S.insert(maxn%(*i));
    }
    if(S.size()<2)cout<<"-1";
    else{
        set<int>::iterator k=S.begin();
        advance(k,S.size()-2);
        cout << *k;
    }
}