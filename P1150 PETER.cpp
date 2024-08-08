#include <iostream>
int main(){
    int n,k,ans;
    std::cin >> n >> k;
    ans = n;
    while(n >= k){
        ans += n / k;
        n = n / k + n % k;
    }
    std::cout << ans;
}