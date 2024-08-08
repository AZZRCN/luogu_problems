#include <bits/stdc++.h>
using namespace std;
int to[8][2] = {
    {1,2},
    {1,-2},
    {2,1},
    {2,-1},
    {-1,2},
    {-1,-2},
    {-2,1},
    {-2,-1}
};
class Node{
    public:
    int x,y,times;
    Node(){
        x = y = times = 0;
    }
    Node(int O1,int O2,int O3){
        x = O1;
        y = O2;
        times = O3;
    }
};
queue<Node> Q;
int BS[401][401];
bitset<401> Vis[401];
int x,y,limx,limy;
void bfs(){
    Q.push(Node(x,y,0));
    BS[x][y] = 0;
    Vis[x][y].flip();
    Node t;
    while(!Q.empty()){
        t = Q.front();
        // cout << "case a time\n";
        Q.pop();
        x = t.x;y = t.y;
        BS[x][y] = t.times;
        for(int i = 0; i < 8; i++){
            int nx = x + to[i][0];
            int ny = y + to[i][1];
            if(nx < 1 || nx > limx || ny < 1 || ny > limy || Vis[nx][ny]){
                continue;
            }
            Vis[nx][ny].flip();
            Q.push(Node(nx,ny,t.times+1));
            // cout << nx << " " << ny << " " << t.times+1 << endl;
        }
    }
    for(int i = 1; i <= limx; i++){
        for(int j = 1; j <= limy; j++){
            if(!Vis[i][j]){cout << "-1\t";continue;}
            cout << BS[i][j] << "\t";
        }
        cout << endl;
    }
}
int main(){
    freopen("in","r",stdin);
    cin >> limx >> limy >> x >> y;
    bfs();
}