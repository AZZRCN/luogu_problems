#include <stdio.h>
int main(){
    int h,r,v=2000000;
    scanf("%d%d",&h,&r);
    h = r*r*314*h;
    r = v / h;
    if(v%h){r++;}
    printf("%d",r);
}