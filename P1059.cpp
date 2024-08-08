#include <iostream>
#include <algorithm>
using namespace std;
int num[100];
bool cmp(int a, int b){
    return a < b;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num,num+n,cmp);
    for(int i = 0; i < n - 1; i++){
        if(num[i] == num[i+1]){
            num[i] = -1;
        }
    }
    cout << n - count(num,num+n,-1) << endl;
    bool first = false;
    for(int i = 0; i < n; i++){
        if(num[i] == -1) continue;
        if(not first){
            first = true;
            
        }
        else{
            cout << " ";
        }
        cout << num[i];
    }
}