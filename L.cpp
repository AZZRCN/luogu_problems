#include <iostream>
using namespace std;
int sus_fib(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return sus_fib(n-1) + sus_fib(n-2);
}
int fib(int n){
    if(n<0) return 0;
    return sus_fib(n);
}
int main(){
    printf("%d",fib(5));

}