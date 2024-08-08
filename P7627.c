#include <stdio.h>
long long cnt[25]={},n,cur,t,sum=0;
int main(){
    // long long n,cur,t;
    scanf("%lld",&n);
    for(long long i = 0 ; i < n; i++){
        cur=0;
        scanf("%lld",&t);
        while(t){
            cnt[cur++] += t%2;
            t/=2;
        }
    }
    for(long long i = 0; i<25;i++){
        sum += (cnt[i]*(n-cnt[i]))<<i;
    }
    printf("%lld",sum);
}