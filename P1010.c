#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void slove(int n){
    int t;
    bool flag = false;
    while(n){
        t = log2(n);
        if(flag) putchar('+');
        if(t == 0) printf("2(0)");
        if(t == 1){
            printf("2");
        }
        if(t>1){
            printf("2(");
            slove(t);
            printf(")");
        }
        n ^= (1 << t);
        flag = true;
    }
}
int main(){
    int n=1315;
    scanf("%d",&n);
    slove(n);
}
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)