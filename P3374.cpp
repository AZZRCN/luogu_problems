#include <bits/stdc++.h>
using namespace std;
template<int x=0>
class treeArray{
    public:
    int next(int n){
        return ((n)&(n-1));
    }
    int next_2(int n){
        int ans=0;
        ans += __builtin_ctz(n);
        n >>= __builtin_ctz(n);
        ans += __builtin_ctz(~n);
        n >>= __builtin_ctz(~n);
        n |= 1;
        n <<= ans;
        return n;
    }
    int array[x+1];
    void change(int pos,int delta_value){//1,1means array[1]+=1
        while(pos <= x){
            array[pos] += delta_value;
            pos = next_2(pos);
        }
    }
    int search(int pos){
        int ret=0;
        while(pos > 0){
            ret += array[pos];
            pos = next(pos);
        }
        return ret;
    }
    int search(int L,int R){
        return search(R) - search(L-1);
    }
    void init(){
        memset(array,0,sizeof(array));
    }
};
int main(){
    treeArray<500000> a;
    a.init();
    int n,m,t,v;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> t;
        a.change(i,t);
    }
    for(int i = 1; i <= m;i++){
        cin >> n >> t >> v;
        if(n == 1){
            a.change(t,v);
        }
        else{
            cout << a.search(t,v) << endl;
        }
    }
}