#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string str;
    int n,sum=0;
    char c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        str = to_string(i);
        sum += count(str.begin(), str.end(), c);
    }
    cout << sum;
}