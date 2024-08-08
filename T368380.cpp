#include <bitset>
#include <iostream>
using namespace std;
bitset<2000000> BS;
bitset<2000000> TBS;
int n;
void slove1(int i){
    TBS = BS;
    int j;
    for(j = 1; j <= i; j++){
        BS[j] = TBS[i + 1 - j];
    }
}
void slove2(int i){
    for(int j = 1; j <= i; j++){
        BS[j].flip();
    }
}
int main(){
    cin >> n;
    bool T;
    for(int i = 1; i <= n; i++){
        cin >> T;
        if(T) BS[i] = 1;
        slove1(i);
        slove2(i);
    }
    for(int i = 1; i <= n; i++){
        cout << BS[i] << " ";
    }
}