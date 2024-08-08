#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
unordered_map<ull,string> _map;//int -> nname
bitset<100005> IrO;//0->内->(0->neg,1->pos),1->外->(1->neg,0->pos)
//a xor b -> 0neg,1pos
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ull pos=1,t1,t2,n,m;
    string name;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> t1 >> name;
        _map.insert(make_pair(i,name));
        if(t1){
            IrO[i].flip();
        }
    }
    while(m--){
        cin >> t1 >> t2;
        if(t1 ^ IrO[pos]){
            pos = (pos + t2-1)%n+1;
        }
        else{
            pos = (pos - t2 + n - 1) % n + 1;
        }
    }
    cout << _map[pos];
}