#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define MXN 40005
using namespace std;
/*
5 5 4

3 1
2 4
5 1
1 4

2 4
3 2
3 5
1 2
4 5
*/
int n,m,s,x,y;
int father[500000][25];
int deepth[500000];
vector<int> sons[500000];
void dfs(int pos,int deep){
    deepth[pos] = deep;
    for(auto k: sons[pos]){
        dfs(k,deep+1);
    }
}
void init_lca(){
    for(int i = 1; i < )
}
void init(){
    dfs(s,0);
}
int main()
{
    cin >> n >> m >> s;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        father[x][0]=y;
        sons[y].push_back(x);
    }
    return 0;
}