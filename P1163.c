#include<stdio.h>
int main()
{
    double yuan,yue,l=0,r=3.1,mid,a;int t;
    scanf("%lf",&yuan);
    scanf("%lf",&yue);
    scanf("%d",&t);
    do{
        mid=(l+r)/2;
        a=yuan;
        for(int i=1;i<=t;i++)
            a=a*(1+mid)-yue;
        if(a>0)r=mid;
        else l=mid;
    }
    while((a!=0&&r-l>=0.0001));
    printf("%.1f",mid*100);
}