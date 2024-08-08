#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <stack>
#include <list>
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
    void insert(size_t O){
        father[O]=O;
        blocks++;
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
		for (int i = 0; i < O; i++) {
			father[i] = i;
		}
		blocks = O;
	}
};
int main() {
    freopen("in","r",stdin);
    UNION<200000> R;
    int n,m,k,x,y;
    cin >> n >> m;
    list<pair<int,int> > l,del;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        if(x>y){swap(x,y);}
        l.push_back(make_pair(x,y));
    }
    unordered_set<int> attacketd;
    stack<int> att,ratt;
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> x;
        attacketd.insert(x);
        att.push(x);
    }
    while(!att.empty()){ratt.push(att.top());att.pop();}
    // R.init(n);
    //检测最后也不会被打击的线路
    for(pair<int,int>t:l){
        if((attacketd.count(t.first) || attacketd.count(t.second))){
            del.push_back(t);
        }
        else{
            R.insert(t.first,t.second);
            // cout << t.first << " " << t.second << endl;
        }
    }
    for(int i = 0; i < n; i++){
        if(!)
    }
    // exit(0);
    //ratt中存放的是被打击的节点
    int cur=0,re=1;
    while(!ratt.empty()){
        cur=0;
        for(;cur<del.size();cur++){
            if(next(del.begin(),cur)->first == ratt.top() || next(del.begin(),cur)->second == ratt.top()){
                cout << next(del.begin(),cur)->first << " " << next(del.begin(),cur)->second << endl;
                R.insert(next(del.begin(),cur)->first,next(del.begin(),cur)->second);
                del.erase(next(del.begin(),cur));
                cur--;
                continue;
            }
        }
        cout << R.blocks << endl;
        ratt.pop();
    }
}