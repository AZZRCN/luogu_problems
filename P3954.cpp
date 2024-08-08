#include <stdio.h>
int main(){
    short a,b,c;
    scanf("%hd%hd%hd",&a,&b,&c);
    a = (a*2 + b * 3 + c * 5) / 10;
    printf("%hd",a);
}