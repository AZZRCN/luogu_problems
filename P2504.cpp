#include <bits/stdc++.h>
using namespace std;
template<size_t x>
class UNION {
public:
	size_t father[x + 1];
	size_t blocks;
	//connect
	void insert(size_t from, size_t to) {
		from = find(from);
		to = find(to);
		if (from == to) return;
		father[from] = to;
		blocks--;
	}
	size_t find(size_t O) {
		if (father[O] == O) {
			return O;
		}
		return father[O] = find(father[O]);
	}
	bool near(size_t from, size_t to) {
		return find(from) == find(to);
	}
	void init() {//success
		for (int i = 1; i <= x; i++) {
			father[i] = i;
		}
		blocks = x;
	}
	void init(int O) {//success
		for (int i = 1; i <= O; i++) {
			father[i] = i;
		}
		blocks = O;
	}
};
priority_queue<int> pq;
class T{
    public:
    int from;//num
    int to;//num
    int w;
    T(int O1,int O2,int O3){from = O1; to = O2;w=O3;}
    T(){}
    bool operator<(const T& O){
        return w < O.w;
    }
};
//from & to -> nn
T e[1000005];
class pos{
    public:
    int x,y;
    pos(){;};
    pos(int O1,int O2){x=O1;y=O2;};
    int operator()(const pos& O){return (int)ceil(sqrt(pow(abs(O.x-x),2)+pow(abs(O.y-y),2)));};//计算距离pos(pos)
};
pos posl[1005];
int main(){
    int m,n,t,len=0,ans=0;
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> t;pq.push(t);
    }
    cin >> n;
    int cur = 1;
    pos tt;
    for(int i = 1; i <= n; i++){
        cin >> tt.x >> tt.y;
        posl[i] = tt;
        for(int j = 1; j < i; j++){
            e[cur++]=T(i,j,posl[j](posl[i]));
        }
    }
    sort(e+1,e+n*(n-1)/2+1);
    UNION<1005> U;
    U.init();
    for(int i = 1; i <= n*(n-1)/2; i++){//记住这个n*(n-1)/2,调了好几天
        if(!U.near(e[i].from,e[i].to)){
            U.insert(e[i].from,e[i].to);
            len = max(len,posl[e[i].from](posl[e[i].to]));
        }
    }
    while(!pq.empty()&&pq.top()>= len){
        ans++;
        pq.pop();
    }
    cout << ans;
}