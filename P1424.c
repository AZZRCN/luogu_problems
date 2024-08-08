#include <stdio.h>
int main(){
    int n,days,t;
    int res=0;
    // scanf("%d%d",&n,&days);
    n= 7;
    days = 543543;
    t = days+n;
    res = (t)/7*5 + (((t)%7)?5:0);
    // res -= (n>5)?5:(n-1);
    // t = 6-n;
    // t = t>0?t:0;
    res -= n-1;
    t = 5-(days+n)%7;
    t = t>0?t:0;
    res -= t;
    printf("%d",(res)*250);
}