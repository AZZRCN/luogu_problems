#include <stdio.h>
#include <stdbool.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
int main(){
    unsigned long long a,b;
    scanf("%lld %lld",&a,&b);
    a%=b;
    unsigned long long i = 1;
    while(((a*i)%b)!=1){i++;}
    printf("%lld",i);
}