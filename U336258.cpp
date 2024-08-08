#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    int n,p;
    for(int i = 1; i <= T; i++){
        cin >> n >> p;
        if(p * 2 + 1 - n > 0){
            cout << -1;
        }
        else{
            for(int j = 1 ; j <= n - p * 2 - 1;j++){
                cout << "0";
            }
            cout << "1";
            for(int j = 1; j <= p;j++){
                cout << "01";
            }
        }
        cout << "\n";
    }
}