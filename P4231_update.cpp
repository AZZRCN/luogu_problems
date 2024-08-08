#include <bits/stdc++.h>
using namespace std;
#define elif else if
template<int x = 0>
class treeArray {
public:
    int next(int n) {
        return ((n) & (n - 1));
    }
    int next_2(int n) {
        int ans = 0;
        ans += __builtin_ctz(n);
        n >>= __builtin_ctz(n);
        ans += __builtin_ctz(~n);
        n >>= __builtin_ctz(~n);
        n |= 1;
        n <<= ans;
        return n;
    }
    int array[x + 1];
    void change(int pos, int delta_value) {//1,1means array[1]+=1
        while (pos <= x) {
            array[pos] += delta_value;
            pos = next_2(pos);
        }
    }
    void change(int L, int R, int delta_value) {//1,1means array[1]+=1
        change(L, delta_value);
        change(R + 1, -delta_value);
    }
    int search(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += array[pos];
            pos = next(pos);
        }
        return ret;
    }
    int search(int L, int R) {
        return search(R) - search(L - 1);
    }
    void init() {
        memset(array, 0, sizeof(array));
    }
};
int main(){
    treeArray<100000> t;
    t.init();
    long long n,m,gc;
    long long lpos,rpos,start_num,end_num;
    long long ans = 0,maxn=0,_tmp;

    cin >> n >> m;
    for(long long i = 1; i <= m; i++){
        cin >> lpos >> rpos >> start_num >> end_num;
        if(lpos == rpos){
            t.change(lpos,  start_num   );
            t.change(rpos+1,-end_num    );
        }
        elif(start_num == end_num){
            t.change(lpos,rpos,start_num);
        }
        else{
            gc = (end_num-start_num)/(rpos-lpos);
            t.change(lpos,start_num);
            for(int i = lpos+1; i <= rpos; i++){
                t.change(i,gc);
            }
            t.change(rpos+1,-end_num);
        }
    }

    for(int i = 1; i<=100000;i++){
        _tmp = t.search(i);
        ans ^= _tmp;
        maxn = max(maxn,_tmp);
    }
    cout << ans << " " << maxn;
}