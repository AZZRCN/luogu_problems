#include <iostream>
using namespace std;
int main(){
    int day=0,unhappy=-1,n,m;
    for(int i = 1; i <= 7; i++){
        cin >> n >> m;
        if(n + m > 8 && n + m > unhappy){
            day = i;
            unhappy = n + m;
        }
    }
    cout << day;
}