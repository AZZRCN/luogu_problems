#include <iostream>
using namespace std;
int main(){
    int n,ans = 0,sum = 0,T;
    for(int i = 1; i <= 12; i++){
        cin >> n;
        T = 300 + ans;//发放+累计
        T -= n;//减去开销,得到剩下的钱
        if(T < 0){
            cout << "-" << i;
            return 0;
        }
        sum += T / 100;//存钱
        T %= 100;//存钱后剩下的钱
        ans = T;//防止被刷新
    }
    cout << ans + sum * 120;
}