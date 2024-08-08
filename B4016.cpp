#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100000];
int ans;
void dfs(int now,int father){
    for(int to: edges[now]){
        if(to == father){continue;}

    }
}
int main(){
    memset()
    int n,from,to;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    dfs();
}