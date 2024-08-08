#include<stdio.h>
long long n,cnt[100],sum=0,a,j;
signed main(){
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		j=0;
		scanf("%lld",&a);
		while(a){
			cnt[j++]+=a%2;//统计每一位 1 的个数
			a/=2;
		}
	}
	for(long long i=0;i<30;i++){
		sum+=cnt[i]*(n-cnt[i])<<i;//算出每一位的异或值
	}
	printf("%lld",sum);
return 0;//完美收尾
}