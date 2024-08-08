#include <bits/stdc++.h>
#define s   signed
#define u   unsigned
#define i   int
#define ui  u   i
#define si  s   i
#define c   char
#define uc  u   c
#define sc  s   c
#define l   long
#define ul  u   l
#define sl  s   l
#define ll  l   l
#define ull u   ll
#define sll s   ll
#define st static
#define co const
#define unless(...) while(!(__VA_ARGS__))
using namespace std;
ull a[500005];
ull t[500005];
queue<ull> q;
//L M R
void M(ull O1, ull O2, ull O3){
    ull cur = O1;
    ull L=O1, R=O2+1;
    while((L != (O2+1)) && (R != (O3+1))){
        if(a[L]<=a[R]){
            t[cur++] = a[L++];
        }
        else{
            t[cur++] = a[R++];
        }
    }
    while(L != (O2+1)){
        t[cur++] = a[L++];
    }
    while(R != (O3+1)){
        t[cur++] = a[R++];
    }
    for(ull I = O1; I <= O3; I++){
        a[I] = t[I];
    }
}
//L && R
void MS(ull O1,ull O2){
    ull mid = (O1>>1)+(O2>>1)+((O1&1)&(O2&1));
    if(O1 < O2){
        MS(O1,mid);
        MS(mid+1,O2);
        M(O1,mid,O2);
    }
}
void slove(int n){
    for(int I = 1;I <= n; I++){
        cin >> a[I];
    }
    MS(1,n);
    for(int I = 1;I <= n; I++){
        cout <<  a[I] << " ";
    }
}
int main(){
    ull n;
    cin >> n;
    slove(n);
}