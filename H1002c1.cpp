#include <iostream>
#include <algorithm>
using namespace std;
unsigned int a[3]={};
int main(){
    unsigned int n,ans=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[0];
        sort(a,a+3,less<int>());
    }
    cout << (int)(a[1]^a[2]);
}