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
class info{
    public:
    int b,e,w;
    bool operator<(const info& O){
        return w < O.w;
    }
}e[10001];
int main(){
    int n,m,k,ans=0;
    cin >> n >> m >> k;
    UNION<1000> U;
    U.init();
    for(int i = 1; i <= m; i++){
        cin >> e[i].b >> e[i].e >> e[i].w;
    }
    sort(e+1,e+m+1);
    k=n-k;
    for(int i = 1; i <= m; i++){
        if(!U.near(e[i].b,e[i].e)){
            ans += e[i].w;
            U.insert(e[i].b,e[i].e);
            k--;
        }
        if(!k){
            cout << ans;
            exit(0);
        }
    }
    cout << "No Answer";
    
}