#include <stdio.h>
int main(){
    unsigned short n,a,b;
    scanf("%hd",&n);
    a = (n&1)^1;
    b = ((((n-5)|(12-n))&0x8000)>>15) ^ 1;
    printf("%d %d %d %d",a&b,a|b,a^b,(a|b)^1);
}