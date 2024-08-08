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
class edge{
    public:
    int from,to,w;
    edge(void){from=to=w=0;};
    edge(int O1,int O2,int O3){from=O1;to=O2;w=O3;};
    bool operator<(const edge& O)const{
        return w<O.w;
    }
};
vector<edge> edges;
int main(){
    UNION<1000> U;
    int N,M;
    cin >> N >> M;
    U.init(N);
    int f,t,w;
    for(int i = 1; i <= M; i++){
        cin >> f >> t >> w;
        edges.push_back(edge(f,t,w));
    }
    sort(edges.begin(),edges.end());
    // int ans = 0;
    for(int i = 0; i < M; i++){
        if(!U.near(edges[i].from,edges[i].to)){
            U.insert(edges[i].from,edges[i].to);
            // ans += edges[i].w;
        }
        if(U.blocks==1){
            cout << edges[i].w;
            // break;
            return 0;
        }
    }
    // cout << ans;
    cout << -1;
    return 0;
}