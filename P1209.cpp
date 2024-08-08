#include <iostream>
#include <list>
using namespace std;
list<int> l;
list<int> delta;
int main(){
    int t,
    m,//要求的模板数量
    s,//牛棚的数量
    c;//牛的数量
    cin >> m >> s >> c;
    if(m >= c){
        cout << c << endl;
        return 0;
    }
    for(int i = 1; i <= c; i++){
        cin >> t;
        l.push_back(t);
    }
    l.sort();
    //输入牛
    l.push_back(s+1);
    l.push_front(0);
    list<int>::iterator it = l.begin();
    for(int i = 1; i <= c; i++){
        delta.push_back(*next(it) - *it - 1);
        it++;
    }
    // printf("[");
	// for (auto K : delta) { std::cout << K << ','; }
	// printf("IS_END]\n");
    // delta.sort();
    // printf("[");
	// for (auto K : delta) { std::cout << K << ','; }
	// printf("IS_END]\n");
    for(int i = m+4; i; i--){
        s -= delta.back();
        delta.pop_back();
    }
    cout << s << endl;
}