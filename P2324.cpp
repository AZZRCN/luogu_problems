#include <bits/stdc++.h>
// #define DEBUG_
using namespace std;
const int fin[5][5]={
1,1,1,1,1,
0,1,1,1,1,
0,0,2,1,1,
0,0,0,0,1,
0,0,0,0,0};
int now[5][5]={};
const int gox[8]={-2,-1, 1, 2, 2, 1,-1,-2};
const int goy[8]={ 1, 2, 2, 1,-1,-2,-2,-1};
int _max=15;
int check(){
    int ret = 0;
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5; j++){
            if(now[i][j]==2)continue;
            ret += (now[i][j]!=fin[i][j]);
        }
    }
    return ret;
}
bool dfs(int x, int y,int deepth){
    int e = check();
    if(e==0){return true;}
    if(deepth+e>_max){return false;}
    int tx,ty;
    for(int i = 0; i < 8; i++){
        tx = x+gox[i];
        ty = y+goy[i];
        if(tx<0||tx>4||ty<0||ty>4) continue;
        swap(now[x][y],now[tx][ty]);
        if(dfs(tx,ty,deepth+1)){return true;}
        swap(now[x][y],now[tx][ty]);
    }
    return false;
}
int cinx,ciny;
void input(){
    char c;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            c = getchar();
            if(c=='*'){
                now[i][j] = 2;
                cinx=i;
                ciny=j;
            }   
            else{
                now[i][j] = c-'0';
            }
        }
        getchar();
    }
}
int main(){
    // freopen("in","r",stdin);
    int t;
    cin >> t;
    getchar();
    for(int k = 1; k <= t; k++){
        input();
        for(_max = 0; _max <= 15; _max++){
            if(dfs(cinx,ciny,0)){
                cout << _max << endl;
                goto label;
            }
        }
        cout << -1 << endl;
        label:
        0;
    }
}