#include <stdio.h>
int main(){
    unsigned char c;
    scanf("%c",&c);
    printf("%c",c ^ 0x20);
}