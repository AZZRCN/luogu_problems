#include <bits/stdc++.h>
using namespace std;
    unsigned long long n,b,p,t=0,ans=0;
unsigned long long qpow(unsigned long long x,unsigned long long y){
	unsigned long long ret = 1;
	while(y){
		if(y&1)	{ret = (ret*x)%p;}
		y>>=1;
		x*=x;
	}
	return ret;
}
int main(){
    cin >> n >> b >> p;
    // while(n--){
    for(int i = 1; i <= n; i++){
        cin >> t;
        ans = max(t,ans);
    }
    ans *= 2;
    // ans <<= 1;
    ans += 233;
    cout << qpow(ans,b)%p;
}