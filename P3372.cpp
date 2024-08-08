#include <bits/stdc++.h>
using namespace std;
constexpr long long MAXN = 400000;

class lineTree{
    public:
    long long a[MAXN+1];
    long long d[MAXN+1];//真值
    long long b[MAXN+1];//懒惰标记
    inline long long ls(long long n){
        return (n<<1);
    }
    inline long long rs(long long n){
        return ((n<<1)|1);
    }
    void build(long long l,long long r,long long p){//左区间，右区间，当前节点编号
        if(l==r){
            d[p]=a[l];
            return;
        }
        long long mid = (l+r)>>1;
        build(l,mid,ls(p));
        build(mid+1,r,rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    void make_b_mark(long long p,long long l,long long r){
        long long m = (l + r)/2;
        d[ls(p)] += b[p] * (m-l+1);
        d[rs(p)] += b[p] * (r-m);
        b[ls(p)] += b[p];
        b[rs(p)] += b[p];
        b[p] = 0;
    }
    void update(long long l,long long r,long long c,long long s,long long t,long long p){
        if(l <= s && t <= r){
            d[p] += (t - s + 1) * c;
            b[p] += c;
            return;
        }
        long long m = (s + t) >> 1;
        make_b_mark(p,s,t);
        if(l <= m) update(l,r,c,s,m,ls(p));
        if(r > m) update(l,r,c,m+1,t,rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    long long sum(long long l,long long r,long long s,long long t,long long p){
        if(l <= s && t<=r)return d[p];
        long long m = (s + t) >> 1;
        make_b_mark(p,s,t);
        long long ret = 0;
        if(l <= m) ret += sum(l,r,s,m,ls(p));
        if(m < r)  ret += sum(l,r,m+1,t,rs(p));
        return ret;
    }
    void operator()(long long n){//上界
        build(1,n,1);
    }
    lineTree(){;};
};
lineTree t;
int main(){
    long long n,m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> t.a[i];
    }
    t(n);
    long long opt,a,b,c;
    for(long long i = 1; i <=m ;i++){
        cin >> opt;
        if(opt == 1){
            cin >> a >> b >> c;
            t.update(a,b,c,1,n,1);
        }
        else{
            cin >> a >> b;
            cout << t.sum(a,b,1,n,1) << endl;
        }
    }
}