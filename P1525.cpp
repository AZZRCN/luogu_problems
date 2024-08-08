#include <bits/stdc++.h>
using namespace std;
template<size_t x>
class UNION {
public:
	size_t father[x + 1];
	//connect
	void insert(size_t from, size_t to) {
		from = find(from);
		to = find(to);
		if (from == to) return;
		father[from] = to;
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
	}
};
class c{
    public:
    unsigned long long from,to,w;
    c(){;}
    bool operator<(const c&O)const{return w<O.w;}
}e[100001];
//
int main(){
    UNION<40000> U;
    int n,m,x,y,z;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> e[i].from >> e[i].to >> e[i].w;
    }
    sort(e+1,e+m+1);
    U.init();
    for(int i = m; i >= 1; i--){
        if(U.near(e[i].from,e[i].to)){
            cout << e[i].w;
            exit(0);
        }
        U.insert(e[i].from,e[i].to+n);
        U.insert(e[i].from+n,e[i].to);
    }
    cout << "0";
}