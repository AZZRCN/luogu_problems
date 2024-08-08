#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
bitset<2000001> AZZR;
void Fill(float a,int t){
    // int T = 0;
    for(int i = 1; i <= t; i++){
        // T = floor(a*i);
        AZZR[floor(a*i)] = not AZZR[floor(a*i)];
    }
}
int main(){
    int n,t;
    float a;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> t;
        Fill(a,t);
    }
    for(int i = 1; i <= 2000000; i++){
        if(AZZR[i]){
            cout << i;
            return 0;
        }
    }
}