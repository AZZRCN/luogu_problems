#include <stdio.h>
int main(){
    int n;
    double d;
    scanf("%d",&n);
    d = n*0.4463;
    if(n > 150){
        d += (n-150)*0.02;
    }
    if(n > 400){
        d += (n-400)*0.1;
    }
    printf("%.1lf",d);
}