#include <bits/stdc++.h>
using namespace std;
unordered_set<int> US;
int num[10]={};
int main(){
    int n,t;
    cin >> n;
    for(int i = 1; i <=7; i++){
        cin >> t;
        US.insert(t);
    }
    int tt=0;
    for(int i = 1; i <= n; i++){
        tt=0;
        for(int j = 1; j <= 7; j++){
            cin >> t;
            if(US.count(t))tt++;
        }
        num[tt]++;
    }
    for(int i = 7; i >= 1; i--){
        cout << num[i] << " ";
    }

}