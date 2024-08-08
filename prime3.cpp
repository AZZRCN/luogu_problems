#include <stdio.h>
#include <vector>
#include <bitset>
using namespace std;
// int pri[N]={2};
// bitset<N> not_prime;
vector<int> pri;
vector<bool> not_prime;
constexpr int N = 101;
int main(){
    not_prime.clear();
    not_prime.resize(N,0);
    pri.push_back(2);
    not_prime[4] = true;
    for(int i = 3; i < N; i += 2){
        if(!not_prime[i]){
            pri.push_back(i);
        }
        for(int j:pri){
            if(i*j>=N){break;}
            if(i%j==0){break;}
            not_prime[i*j] = true;
        }
    }
    int cur = 0;
    for(int k:pri){
        printf("%d ",k);
        cur++;
        if(cur == 5){
            cur = 1;
            printf("\n");
        }
    }
}