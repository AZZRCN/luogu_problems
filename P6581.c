#include <stdio.h>
unsigned long long U;
void main(){
    scanf("%llu",&U);
    printf("%llu",((U >> 63) || U == 0)? 0 : ((U << 1) - 1));
    
}