#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n; 
    for(int i = n; i >= 1; i--){
        if(i % n == 0){
            cout << n;
            return 0;
        }
    }
}