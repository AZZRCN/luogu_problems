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
/*
1~n A类
n+1~2n B
2n+1~3n C
+n表示下一类(被被吃)
+2n表示上一类(主吃的)
*/
int main(){
    int n,k,x,y,z,ans=0;
    cin >> n >> k;
    UNION <150000>U;
    U.init();
    for(int i = 1; i <= k ; i++){
        cin >> z >> x >> y;
        if(x > n || y > n){ans++;continue;}
        //x吃y
        if(z == 2){
            if(x == y) {ans++;continue;}
            if(U.near(x,y+2*n) || U.near(x,y)){
                ans++;
                continue;
            }
            U.insert(x,y+n);
            U.insert(x+n,y+2*n);
            U.insert(x+2*n,y);
        }
        else{
            if(U.near(x,y+n) || U.near(x,y+2*n)){
                ans++;
                continue;
            }
            U.insert(x,y);
            U.insert(x+n,y+n);
            U.insert(x+2*n,y+2*n);
        }
    }
    cout << ans;
}