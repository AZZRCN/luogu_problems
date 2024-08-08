#include <iostream>
using namespace std;
int main(){
    int K;
    bool yes = false;
    cin >> K;
    for(int i = 10000; i <= 30000; i++){
        if(((i % 1000) % K == 0) && (((i / 10) % 1000) % K == 0) && ((i / 100) % K == 0)){
            cout << i << endl;
            yes = true;
        }
    }
    if(not yes){
        cout << "No";
    }
}