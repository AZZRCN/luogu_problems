#include <bits/stdc++.h>
using namespace std;
static inline unsigned long long qpow(unsigned long long base,unsigned long long pow_time,unsigned long long mod){
	unsigned long long ret = 1;
	while(pow_time){
		if(pow_time&1)	ret =(ret*base)%mod;
		pow_time>>=1;
		base=(base*base)%mod;
	}
	return ret;
}
int main(){
    unsigned long long m , n;
    cin >> m >> n;
    unsigned long long ans = qpow(m,n,100003)-((m*qpow(m-1,n-1,100003))%100003);
    cout << (ans+100003)%100003;
}