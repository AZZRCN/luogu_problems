#include <iostream>
using namespace std;
int num[10];
int main(){
    for(int i = 0 ; i < 10; i++){
        cin >> num[i];
    }
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < 10; i++){
        if(num[i] <= n+30){
            ans++;
        }
    }
    cout << ans;
}