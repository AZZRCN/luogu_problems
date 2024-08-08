#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,A=INT_MAX,O=0,X=0;
    cin >> n >> m;
    string str;
    for(int i = 1; i <= n; i++){
        cin >> str >> t;
        if(str =="AND"){
            A &= t;
        }
        if(str == "OR"){
            O |= t;
        }
    }
}