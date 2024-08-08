#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1.1e7+5;
char s[N];
int n,a[N];
int fw[N];
int bw[N];
int pw[N];
const int md = 1e9+7;
const int p = 31;
int substr_hash_fs(int l,int r){
    return ((fw[r]-(ll)fw[l-1]*pw[l-r+1])%md+md)%md;
}
int substr_hash_bw(int l,int r){
    return ((bw[l]-(ll)bw[r+1]*pw[r-l+1])%md+md)%md;
}
bool is_huiwen(int l,int r){
    if(l == r){
        return true;
    }
    return substr_hash_bw(l,r) == substr_hash_fs(l,r);
}
int mx[N];

int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    for(int i = 1; i <= n; i++){
        a[i] = s[i]-'a';
    }
    pw[0]=1;
    for(int i = 1; i <= n; i++){
        pw[i] = ((ll)pw[i-1]*p)%md;
    }
    for(int i = 1; i <= n; i++){
        fw[i] = ((long long)fw[i-1]*p+a[i])%md;
    }
    for(int i = n; i >= 1; i--){
        bw[i] = ((long long)bw[i+1]*p+a[i])%md;
    }
    for(int i = 1; i<= n; i++){
        mx[i] = min(mx[i-1]+2,i);
        while(!is_huiwen(i-mx[i]+1,i)){
            --mx[i];
        }
    }
    int ans=0;
    for(int i = 1; i <= n; i++){
        ans = max(ans,mx[i]);
    }
    cout << ans;
}