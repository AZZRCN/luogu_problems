#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const               long    long N      = 1.1e7+5   ;
                    long    long n                  ;
const               long    long md     = 1e9+7     ;
const               long    long p      = 31        ;
        unsigned    long    long pvalue [N]         ;
long long substr_hash_fs(long long l,long long r){
}
long long substr_hash_bw(long long l,long long r){
}
bool is_huiwen(long long l,long long r){
    if(l == r){
        return true;
    }
    return substr_hash_bw(l,r) == substr_hash_fs(l,r);
}
long long mx[N];
int main(){
    pvalue[0]=1;
    string str;
    cin >> str;
    n = str.length();
    for(long long i = 1; i < n; i++){
        pvalue[i] = (pvalue[i-1]*p)%mod;
    }
}