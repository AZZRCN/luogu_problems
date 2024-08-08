#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N,cnt=1;
    string str,tig;
    cin >> N >> tig;
    for(int i = 1; i <= N; i++){
        str.push_back('0'+i);
        //cout << str << endl;
    }
    //exit(0);
    while(str != tig){
        cnt++;
        //cout << str << endl;
        next_permutation(str.begin(), str.end());
    }
    cout << cnt;
}