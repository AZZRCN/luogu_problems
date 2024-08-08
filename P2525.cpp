#include <iostream>
#include <bits/stl_algo.h>
using namespace std;
int N;
int list[10];
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d",&list[i]);
    }
    prev_permutation(list+1,list+N+1);
    for(int i = 1; i <= N; i++){
        printf("%d ",list[i]);
    }
}