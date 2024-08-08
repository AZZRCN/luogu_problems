#include <stdio.h>
#include <vector>
#include <bitset>
using namespace std;
// vector<int> pri;
    // pri.push_back(2);
    // for(int i = 2; i < N; i += ((i == 2)?1:2)){
            // pri.push_back(i);
        // for(int j:pri){
            // if(i*j>=N){break;}
            // if(i%j==0){break;}
    // for(int k:pri){
#define N 100
int pri[N]={2};
bitset<N> notprime;
int main(){
    notprime[4] = true;
    int head = 1;
    for(int i = 3; i < N; i += 2){
        if(!notprime[i]){
            pri[head++]=i;
        }
        for(int j = 0; j < N; j++){
            if(i*pri[j]>=N){break;}
            notprime[i*j] = true;
        }
    }
    int cur = 0;
    for(int i = 0; i < N && pri[i] != 0; i++){
        printf("%d ",pri[i]);
        cur++;
        if(cur == 5){
            cur = 1;
            printf("\n");
        }
    }
}