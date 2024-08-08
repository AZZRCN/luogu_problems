#include <iostream>
#include <bitset>
using namespace std;
short a[10000];
bitset<10000> b1,b2;
int main() {
    int n,t=-1,cnt = 0;scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b1[i] = a[i] < t;
        t = t > a[i] ? t : a[i];
    }
    t = -1;
    for(int i = n - 1; i >= 0 ; i--){
        b2[i] = a[i] < t;
        t = t > a[i] ? t : a[i];
    }
    b1 &= b2;
    t = 0;
    for(int i = 0; i < n; i++){
        if(b1[i] && not t){
            t = 1;
        }
        if(not b1[i] && t){
            t = 0;
            cnt++;
        }
    }
    cout << cnt;
}