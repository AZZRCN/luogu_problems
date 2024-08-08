#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 5e5+1;
const unsigned long long M = 1e9+7;
unsigned long long a[N+1],b[N+1];
unsigned long long pa[N+1],pb[N+1];
unsigned long long ppa[N+1],ppb[N+1];
int main(){
    // freopen("in","r",stdin);
    unsigned long long n;
    cin >> n;
    pa[0]=ppa[0]=pb[0]=ppb[0]=0;
    for(unsigned long long i=1;i<=n;i++){
        cin >> a[i];
        a[i] = (a[i])%M;
        pa[i] = (pa[i-1]+a[i])%M;
        ppa[i] = (ppa[i-1]+pa[i])%M;
    }
    for(unsigned long long i=1;i<=n;i++){
        cin >> b[i];
        b[i] = (b[i])%M;
        pb[i] = (pb[i-1]+b[i])%M;
        ppb[i] = (ppb[i-1]+pb[i])%M;
    }
    unsigned long long part[5]={0 ,0 , 0, 0 , 0};
    for(unsigned long long r = 1; r <= n; r++){//is r
        part[1] = (part[1]+r*pa[r]*pb[r])%M;
    }
    for(unsigned long long r = 1; r <= n; r++){//is r
        part[2] = (part[2]+pb[r]*ppa[r])%M;
    }
    for(unsigned long long r = 1; r <= n; r++){//is r
        part[3] = (part[3]+pa[r]*ppb[r])%M;
    }
    for(unsigned long long l = 1; l <= n; l++){//is l
        part[4] = (part[4]+(n-l+1)*pa[l - 1]*pb[l - 1])%M;
    }
    cout << ((part[1] - part[2] - part[3]+part[4]+5*M)%M) << endl;
}