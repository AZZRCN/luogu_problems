#include <stdio.h>
int main(){
    unsigned long long base,pow_time,mod,pow_time2,base2;
    // cin >> base >> pow_time >> mod;
	scanf("%lld%lld%lld",&base,&pow_time,&mod);
	pow_time2=pow_time;
	base2=base;
	unsigned long long ret = 1;
	while(pow_time){
		if(pow_time&1)ret =(ret*base)%mod;
		pow_time>>=1;
		base=(base*base)%mod;
	}
    printf("%d^%d mod %d=%lld",base2,pow_time2,mod,ret);
}