#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define r(...) return __VA_ARGS__
#define ull unsigned long long
int n;
int ans=0;
//纵向deepth
//decided从[1]开始
//2 4 6 1 3 5
//wid = 5
//decided = {2,4,6,1}
//need:
//cantinsert{2,4,6,1}
void dfs(int deepth,vector<int> decided){
    //decided from 1 ~ n-1
    if(deepth == n+1){
        for(auto k: decided){
            cout << k << " ";
        }
        cout << endl;
        ans++;
        // cout << ans++ << endl;
        r();
    }
    unordered_set<int>CI;
    //判断当前行不能取得位置
    for(int i = 1; i < deepth; i++){
        CI.insert(decided[i]);
        CI.insert(decided[i] + deepth - i); CI.insert(decided[i] - deepth + i);
    }
    //列举
    decided.push_back(1);
    for( auto k: CI){
        cout << k << " ";
    }
    cout << endl ;
    int t;
    cin >> t;
    for(int i = 1; i <= n; i++){
        if(CI.count(i)) {continue;}
        decided.back() = i;
        dfs(deepth+1, decided);
    }
    return;
}
int main(){
    // cin >> n;
    n=6;
    dfs(0,vector<int>(1,0));
    cout << ans;
}