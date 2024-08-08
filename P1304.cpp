#include <iostream>
using namespace std;
bool isprime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void solve(int n){
    for(int i = 2; i << 1 <= n; i++){
        if(isprime(i) && isprime(n - i)){
            printf("%d=%d+%d\n",n,i,n-i);
            return ;
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 4; i <= n; i += 2){
        solve(i);
    }
}