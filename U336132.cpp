#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        if(s != "AC"){
            cout << i;
            if(i != n){
                cout << " ";
            }
        }
    }
}