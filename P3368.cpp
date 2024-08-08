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
    void change(int L,int R,int delta_value){//1,1means array[1]+=1
        change(L,delta_value);
        change(R+1,-delta_value);
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
    int n,last=0,now,m,x1,x2,x3,x4;
    cin >> n >> m;
    treeArray<500000> T;
    T.init();
    for(int i = 1; i <= n; i++){
        cin >> now;
        T.change(i,now-last);
        last = now;
    }
    for(int i = 1; i <= m; i++){
        cin >> x1 >> x2;
        if(x1 == 1){
            cin >> x3 >> x4;
            T.change(x2,x3,x4);
        }
        else{
            cout << T.search(x2) << endl;
        }
    }
}