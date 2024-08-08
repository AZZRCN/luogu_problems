#include <bits/stdc++.h>
using namespace std;
vector<string> mins,maxs;
int main(){
    int n,m;
    cin >> n >> m;
    string str;
    mins.push_back("");
    maxs.push_back("");
    for(int i = 1; i <= n; i++){
        cin >> str;
        sort(str.begin(),str.end());
        mins.push_back(str);
        reverse(str.begin(),str.end());
        maxs.push_back(str);
    }
    bool flag=true;
    for(int i = 1; i <= n ; i++){
        flag = true;
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            if(mins[i] >= maxs[j]){
                cout << "0";
                j=n;
                flag = false;
                continue;
            }
        }
        if(flag)cout << "1";
    }
}