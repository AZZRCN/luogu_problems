#include <bits/stdc++.h>
using namespace std;
#define elif else if
class pos{
    public:
    int x,y;
    pos(int O1,int O2){
        x = O1;
        y = O2;
    }
};
class Node {
public:
    int x, y;
    int face;
    int times;
    // stack<pos> history;
    Node(int O1, int O2, int O3, int O4) {x = O1;y = O2;face = O3;times = O4;}
    // Node(int O1, int O2, int O3, int O4,Node O5) {x = O1;y = O2;face = O3;times = O4;history = O5.history;}
    Node(int O1, int O2, int O3, int O4,Node O5) {x = O1;y = O2;face = O3;times = O4;}
    Node() { x = y = times = 0; }
};

struct EQ {bool operator()(const Node& L, const Node& R) const {return L.x == R.x && L.y == R.y && L.face == R.face && L.times == R.times;}};
struct HS {bool operator()(const Node& L) const {return hash<int>()(L.x) ^ hash<int>()(L.y) ^ hash<int>()(L.face) ^ hash<int>()(L.times);}};

unordered_set<Node, HS, EQ> US;
// f(x) minstep = min(minstep, step)
// if < kill self
int m, // m<=>y
    n; // n<=>x
int sx, sy, fx, fy,
    Gface = 1; // 0E1S2W3N
// 0X+1Y+2X-3Y-
bitset<51> MAP[51];
// first y second x
// [y][x]
// [m][n]
int cango[401][401]={};
//对于网格到块的转换
//第二象限，向左上的块
void find_cango() {
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            cango[i][j] = (MAP[i][j]);
        }
    }
}

void bfs() {
    // for(int i = 1; i < m; i++){
    //     for(int j = 1; j < n; j++) {
    //         cout << cango[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    queue<Node> q;
    q.push(Node(sx, sy, Gface, 0));
    US.insert(Node(sx, sy, Gface, 0));
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        if(t.x < 1 || t.x > n || t.y < 1 || t.y > m) continue;
        if(cango[t.x][t.y]) continue;
        // if(US.count(t)) continue;
        if (t.x == fx && t.y == fy) {
            cout << t.times;
            // while(!t.history.empty()) {
            //     cout << endl << t.history.top().x << " " << t.history.top().y;
            //     t.history.pop();
            // }
            return;
        }
        US.insert(t);
        // cout << t.x << " " << t.y << endl;
        // t.history.push(pos(t.x, t.y));
        if (t.face == 0) {
            // if(!cango[t.x+1][t.y] && t.x < n - 0)
                q.push(Node(t.x + 1, t.y, t.face, t.times + 1,t));
                // if(!cango[t.x+2][t.y] && t.x < n - 1)
                    q.push(Node(t.x + 2, t.y, t.face, t.times + 1,t));
                    // if(!cango[t.x+3][t.y] && t.x < n - 2)
                        q.push(Node(t.x + 3, t.y, t.face, t.times + 1,t));
        } elif (t.face == 1) {
            // if(!cango[t.x][t.y+1] && t.y < m - 0)
                q.push(Node(t.x, t.y + 1, t.face, t.times + 1,t));
                // if(!cango[t.x][t.y+2] && t.y < m - 1)
                    q.push(Node(t.x, t.y + 2, t.face, t.times + 1,t));
                    // if(!cango[t.x][t.y+3] && t.y < m - 2)
                        q.push(Node(t.x, t.y + 3, t.face, t.times + 1,t));
        } elif(t.face == 2) {
            // if(!cango[t.x-1][t.y] && t.x > 1)
                q.push(Node(t.x - 1, t.y, t.face, t.times + 1,t));
                // if(!cango[t.x-2][t.y] && t.x > 2)
                    q.push(Node(t.x - 2, t.y, t.face, t.times + 1,t));
                    // if(!cango[t.x-3][t.y] && t.x > 3)
                        q.push(Node(t.x - 3, t.y, t.face, t.times + 1,t));
        } else {
            // if(!cango[t.x][t.y-1] && t.y > 1)
                q.push(Node(t.x, t.y - 1, t.face, t.times + 1,t));
                // if(!cango[t.x][t.y-2] && t.y > 2)
                    q.push(Node(t.x, t.y - 2, t.face, t.times + 1,t));
                    // if(!cango[t.x][t.y-3] && t.y > 3)
                        q.push(Node(t.x, t.y - 3, t.face, t.times + 1,t));
        }
        // for turn condition
        if (!US.count(Node(t.x, t.y, (t.face + 1) % 4, t.times + 1,t))) {
            q.push(Node(t.x, t.y, (t.face + 1) % 4, t.times + 1,t));
        }
        if (!US.count(Node(t.x, t.y, (t.face + 3) % 4, t.times + 1,t))) {
            q.push(Node(t.x, t.y, (t.face + 3) % 4, t.times + 1,t));
        }
    }
}

int main() {
    freopen("in", "r", stdin);
    cin >> m >> n;
    int t;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            if (t) {
                MAP[i][j] = true;
            }
        }
    }
    cin >> sy >> sx >> fy >> fx;
    find_cango();
    bfs();
}