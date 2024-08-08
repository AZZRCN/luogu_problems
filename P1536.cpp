#include <iostream>
using namespace std;
template<size_t x>
class UNION {
public:
	size_t father[x+1];
    size_t blocks;
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
        blocks=x;
    }
    void init(int O){//success
        for(int i = 1; i <= O; i++){
            father[i]=i;
        }
        blocks=O;
    }
};
int main(){
    // freopen("in","r",stdin);
    int m,n;
    cin >> m;
    UNION<1000> U;
    while(m != 0){
        cin >> n;
        U.init(m);
        int from,to;
        for(int i = 1; i <= n; i++){
            cin >> from >> to;
            U.insert(from,to);
        }
        cout << U.blocks-1 << endl;
        cin >> m;
    }
}