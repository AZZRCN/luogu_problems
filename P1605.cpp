#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool> > map_;
int ans=0;
//x与n绑定
//y与m绑定
int m,n,t,sx,sy,fx,fy;
#define r(...) return __VA_ARGS__
#define ull unsigned long long
void bfs(int nx,int ny,vector<vector<bool> > carry_map){
    if(nx < 1 || nx > n || ny < 1 || ny > m || carry_map[nx][ny]) r();
    if(nx == fx && ny == fy){
        ans++;
        return;
    }
    carry_map[nx][ny] = true;
    bfs(nx+1,ny,carry_map);
    bfs(nx-1,ny,carry_map);
    bfs(nx,ny+1,carry_map);
    bfs(nx,ny-1,carry_map);
}
int main(){
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    map_.resize(m+1,vector<bool>(n+1,false));
    int t1,t2;
    for(int i = 1; i <= t; i++){
        cin >> t1 >> t2;
        map_[t1][t2] = true;
    }
    bfs(sx,sy,map_);
    cout << ans;
}