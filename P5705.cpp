#include <bits/stl_algo.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    reverse(str.begin(),str.end());
    cout << str;
}