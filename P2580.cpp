#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> slove_map;
int main() {
    string str;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> str;
        slove_map.insert(make_pair(str,0));
    }
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> str;a
        if(slove_map.find(str) == slove_map.end()){
            puts("WRONG");
        }
        else{
            if(!slove_map[str]){
                puts("OK");
                slove_map[str]=1;
            }
            else{
                puts("REPEAT");
            }
        }
    }
}