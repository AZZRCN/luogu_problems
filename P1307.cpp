#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n < 0){
        printf("-");
    }
    n = n > 0 ? n : -n;
    while(n && n % 10 == 0){
        n /= 10;
    }
    if(n == 0){
        printf("0");
        return 0;
    }
    while(n){
        printf("%d", n%10);
        n /= 10;
    }
}