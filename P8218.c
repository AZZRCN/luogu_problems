#include <stdio.h>
int S[100001];
int main(){
    int n,t,m;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&t);
        S[i] = S[i-1]+t;
    }
    scanf("%d",&m);
    for(m;m; m--){
        scanf("%d %d",&n,&t);
        printf("%d\n",S[t] - S[n-1]);
    }
}