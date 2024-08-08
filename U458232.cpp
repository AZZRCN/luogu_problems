#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int n,m;
        cin >> m >> n;//数字,长度
        if((n%2==1)^(m==0)){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
}