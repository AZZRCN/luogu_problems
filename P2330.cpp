#include <iostream>
#include <algorithm>
using namespace std;
class info{
    public:
    int b,e,w;
    bool operator<(const info& O){
        return w < O.w;
    }
}e[10001];
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
int main(){
    UNION<300> U;
    int n,m,cur=0,ans=0;
    cin >> n >> m;
    for(int i = 1; i <= m ; i++){
        cin >> e[i].b >> e[i].e >> e[i].w;
    }
    sort(e+1,e+m+1);
    U.init();
    for(int i = 1; i <= m ; i++){
        if(!U.near(e[i].b,e[i].e)){
            cur++;
            ans = max(ans,e[i].w);
            U.insert(e[i].b,e[i].e);
        }
    }
    cout << cur << " " << ans;
}