#include <bits/stdc++.h>
using namespace std;
list<int> L;
map<int, list<int>::iterator> M;//x = L[x]
int main(){
    int n,a,b,c;
    cin >> n;
    L.push_back(1);
    M.insert(make_pair(1, L.begin()));
    list<int>::iterator p = L.begin();
    int add=2;
    for(int i = 1; i <= n;i++){
        cin >> a >> b;
        if(a == 1){
            cin >> c;
            L.insert(next(M[b]),c);
            M.insert(make_pair(c,next(M[b])));
        }
        if(a == 2){
            cout << *next(M[b]) << endl;
        }
        if(a == 3){
            p = next(M[b]);
            M.erase(*p);
            L.erase(p);
        }
    }
}