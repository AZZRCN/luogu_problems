#include <iostream>
#include <cstring>
using namespace std;
template<size_t x>
class UNION {
public:
	size_t father[x+1];
	void insert(size_t from,size_t to){
		if (from == to) return;
		from = find(from);
		to = find(to);
		father[from] = to;
	}
	size_t find(size_t O) {
		if (father[O] == O) {
			return O;
		}
		return father[O] = find(father[O]);
	}
	size_t near(size_t from, size_t to) {
		return find(from) == find(to);
	}
    void init(){
        for(int i = 1; i <= x; i++){
            father[i]=i;
        }
    }
};
int main(){
    int n,m,p,from,to;
    cin >> n >> m >> p;
    UNION <5000>U;
    U.init();
    for(int i = 1; i <= m; i++){
        cin >> from >> to;
        U.insert(from,to);
    }
    for(int i = 1; i <= p; i++){
        cin >> from >> to;
        if(U.near(from,to)){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
}