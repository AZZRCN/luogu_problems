#include <bits/stdc++.h>
using namespace std;
template<size_t x>
class UNION {
public:
	size_t father[x+1];
    size_t blocks=x;
    //connect
	void insert(size_t from,size_t to){
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
    void init(){//success
        for(int i = 1; i <= x; i++){
            father[i]=i;
        }
    }
};
int main(){
    int n,m,z,y,x;
    UNION<10000> U;
    cin >> n >> m;
    U.init();
    for(int i = 1; i<= m; i++){
        cin >> z >> x >> y;
        if(z == 1){
            U.insert(x,y);
        }
        else{
            if(U.near(x,y)){
                puts("Y");
            }
            else{
                puts("N");
            }
        }
    }
}