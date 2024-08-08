#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define u unsigned
#define ull u ll
#define r(...) return __VA_ARGS__
#define N 100005
ll m,n;
char R[N],S[N];
int hr[N],hs[N];
static int md = 1000000007;
static int p = 31;
int pw[N];
bool match(ll lr,ll rr,ll ls){
    ll len= rr-lr+1;
    ll RH = (hr[rr]-(ll)hr[lr-1]*pw[len]%md+md)%md;
    ll SH = (hs[ls+len-1]-(ll)hs[ls-1]*pw[len]%md+md)%md;
    return RH == SH;
}
int find(ll lr, ll rr, ll ls){
    //返回第一个不同的位置对于R偏移量
    //R
    int len = rr-lr+1;
    int l = 1,r=len;
    while(l<r){
        int mid = (l+r)>>1;
        if(match(lr,lr+mid-1,ls)){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    r(l);
}
int ans;
void slove(){
    if(n<m){
        puts("0");
        return;
    }
    pw[0]=1;
    for(int i = 1; i <= n; i++){
        hr[i] = ((ll)hr[i-1]*p+R[i]-'a')%md;
        pw[i] = (ll)pw[i-1]*p%md;
    }
    for(int i = 1; i <= m; i++){
        hs[i] = ((ll)hs[i-1]*p+S[i]-'a')%md;
    }
    ans = 0;
    for(int i = 1; i + m - 1 <= n; i++){
        if(match(i,i+m-1,1)){
            ans++;
            continue;
        }
        //第一个
        int f = find(i,i+m-1,1);
        if(match(i+f,i+m-1,1+f)){
            ans++;
            continue;
        }
        f += find(i+f,i+m-1,1+f);
        if(match(i+f,i+m-1,1+f)){
            ans++;
            continue;
        }
        f += find(i+f,i+m-1,1+f);
        if(match(i+f,i+m-1,1+f)){
            ans++;
            continue;
        }
        //None
        NULL;
    }
}
int main(){
    ull a,n,m;
    int t;
    cin >> t;
    while(t--){
        cin >> R+1 >> R+1;
        n =strlen(R+1);
        m=strlen(S+1);
        slove();
        cout << ans;
    }
}