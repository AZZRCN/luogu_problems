#include <stdio.h>
int max(short L,short R){return L<R?R:L;};
int main(){
    short m,t,s;
    scanf("%hd%hd%hd",&m,&t,&s);
    if(not t){printf("0");return 0;}
    s = s/t +((s%t)?1:0);
    printf("%d",max(m-s,0));
}