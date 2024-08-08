#include <iostream>
#include <bitset>
using namespace std;
bitset<100000000> JOK;
int main(){
    int n,last,dis;
    cin >> n;
    for(int i = 1; i <= n; i++){
        last = dis;
        cin >> dis;
        if(i == 1) continue;
        JOK[abs(last - dis)] = true;
    }
    for(int i = 1; i < n; i++){
        if(JOK[i] == false){
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
}