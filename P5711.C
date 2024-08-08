#include <stdio.h>
int main(){
    short n;
    scanf("%hd",&n);
    printf("%d",n&3 == 0 || (n%100 == 0 && n % 400 == 0));
}