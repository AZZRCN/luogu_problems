#include <iostream>
using namespace std;
int main(){
    int k,m,n;
    cin >> k >> m >> n;
    int a,b,c=0;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        if(a == 0){
            if(b > 0){
                cout << i << " ";
                c++;
            }
            continue;
        }
        if((k / a) * b >= n){
            cout << i << " ";
            c++;
        }
    }
    if(c == 0){
        cout << -1;
    }
}