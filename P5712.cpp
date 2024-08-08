#include <stdio.h>
int main(){
    short n;
    scanf("%hd",&n);
    printf("Today, I ate %d apple%s",n,(n>1)?"s.":".");
}