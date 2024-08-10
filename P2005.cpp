#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5001];
int D[5001];
int main(){
    long long di;
    memset(a,0,sizeof(a));
    memset(D,0,sizeof(D));
    string str;
    cin >> str;
    cin >> di ;
    reverse(str.begin(),str.end());
    for(int i = 0 ; i < str.length(); i++){
        D[5000-i] = str[i]-'0';
    }
    long long carry = 0;
    for(int i = 1; i <= 5000; i++){
        carry = carry*10 + D[i];    
        a[i] = carry / di;
        carry %= di;
    }
    int i = 1;
    for(; i <= 5000; i++){
        if(a[i])break;
    }
    if(i == 5001){
        cout << "0";
        return 0;
    }
    for(; i <= 5000; i++){
        cout << a[i];
    }
}