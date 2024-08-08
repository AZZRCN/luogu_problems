#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,Q,a,b,c;
    cin >> n >> Q;
    vector<int> V;
    for(int i = 1; i <= n;i++){
        cin >> a;
        V.push_back(a);
    }
    for(int i = 1; i<= Q;i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            V[b-1]=c;
        }
        if(a==2){
            cin>>b;
        }
    }
}