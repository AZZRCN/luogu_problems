#include <iostream>
#include <cstring>
#define ull unsigned long long
using namespace std;
// static inline constexpr ull MAXN = (const ull)800000;
#define MAXN 800000
ull n, m, mod;
enum operations {
    MULTI = 1,
    ADD = 2,
    QUERY = 3
};
class lineTree {
public:
    ull a[MAXN + 1];
    ull _val[MAXN + 1];//真值 
    ull b[MAXN + 1];//懒惰标记
    ull k[MAXN + 1];//懒惰标记
    inline ull ls(ull n) {
        return (n << 1);
    }
    inline ull rs(ull n) {
        return ((n << 1) | 1);
    }
    void build(ull l, ull r, ull p) {//左区间，右区间，当前节点编号
        b[p] = 0;
        k[p] = 1;
        if (l == r) {
            _val[p] = a[l]%mod;
            return;
        }
        ull mid = ((l + r) / 2);
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        _val[p] = (_val[ls(p)] + _val[rs(p)])%mod;
        // dbg();
        // dbg_2();
    }
    void pass_b_mark(ull pos, ull l, ull r) {
        ull m = (l + r) / 2;
        _val[ls(pos)] += (b[pos] * (m - l + 1))%mod;
        _val[rs(pos)] += (b[pos] * (r - m))%mod;
        b[ls(pos)] += b[pos]%mod;
        b[rs(pos)] += b[pos]%mod;
        b[pos] = 0;
    }
    void pass_k_mark(ull pos) {
        _val[ls(pos)] *= k[pos]%mod;
        _val[rs(pos)] *= k[pos]%mod;
        k[ls(pos)] *= k[pos]%mod;
        k[rs(pos)] *= k[pos]%mod;
        b[ls(pos)] *= k[pos]%mod;
        b[rs(pos)] *= k[pos]%mod;
        k[pos] = 1;
    }
    void builtin(ull pos,ull l,ull r){
        pass_k_mark(pos);
        pass_b_mark(pos,l,r);
        _val[ls(pos)] %= mod;
        _val[rs(pos)] %= mod;
        k[ls(pos)] %= mod;
        k[rs(pos)] %= mod;
        b[ls(pos)] %= mod;
        b[rs(pos)] %= mod;
    }
    void builtin(void){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(k,0,sizeof(k));
        memset(_val,0,sizeof(_val));
    }
    void update(ull l,ull r,ull c,ull s,ull t,ull p,ull opt){
        builtin(p,s,t);
        // if(l>r) return;
        if(l <= s && t <= r){
            if(opt == ADD){
                _val[p] += (t - s + 1) * c;
                b[p] += c;
            }
            else{
                _val[p] *= c;
                k[p] *= c;
                b[p] *= c;
            }
            _val[p] %=mod;
            b[p] %= mod;
            k[p] %= mod;
            return;
        }
        ull m = (s + t) >> 1;
        if(l <= m) update(l,r,c,s,m,ls(p),opt);
        if(r > m) update(l,r,c,m+1,t,rs(p),opt);
        _val[p] = (_val[ls(p)] + _val[rs(p)])%mod;
    }
    ull sum(ull l, ull r, ull s, ull d, ull p) {
        builtin(p, s, d);
        if (l <= s && d <= r)return _val[p];
        ull m = ((s + d) >> 1);
        ull ret = 0;
        if (l <= m) ret += sum(l, r, s, m, ls(p));
        if (m < r)  ret += sum(l, r, m + 1, d, rs(p));
        return ret%mod;
    }
    lineTree() { ; };
};
lineTree t;
int main() {
    t.builtin();
    cin >> n >> m >> mod;
    for (ull i = 1; i <= n; i++) {
        cin >> t.a[i];
    }
    t.build(1, n, 1);
    ull opt,a,b,c;
    for(ull i = 1; i <=m ;i++){
        cin >> opt;
        cin >> a >> b ;
        if(a>b)swap(a,b);
        if(opt == ADD || opt == MULTI){
            cin >> c;
            t.update(a,b,c,1,n,1,opt);
        }
        else{
            cout << t.sum(a,b,1,n,1)%mod << endl;
        }
    }
    system("pause");
}