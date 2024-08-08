#include <stdio.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
void slove(const& unsigned long long L,const& unsigned long long R){
    unsigned long long TT,TL=L,TR=R;
    while (TR)
	{
	  TT = TL % TR;
	  TL = TR;
	  TR = TT;
	}
    TT = TL;
    printf("%lld/%lld",R/TT,L/TT);
}
int main(){
    unsigned long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    slove(max(max(a,b),c),min(min(a,b),c));
}