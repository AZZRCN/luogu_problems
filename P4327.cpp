#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    string out[3];
    cin >> str;
    out[0] += ".";
    out[1] += ".";
    out[2] += "#";
    for(int i = 0; i < str.length(); i++){
        out[0] += ".";
        if((i+1) % 3 == 0){
            out[0] += "*";
            out[1] += "*.*";
            out[2] += "*.";
            out[2] += str[i];
            out[2] += ".*";
        }
        else{
            out[0] += "#";
            out[1] += "#.#";
        }
        if((i+1) % 3 == 1){
            out[2] += ".";
            out[2] += str[i];
            out[2] += ".#";
        }
        if((i+1) % 3 == 2){
            out[2] += ".";
            out[2] += str[i];
            out[2] += ".";
        }
        out[0] += "..";
        out[1] += ".";
    }
    if(str.length() % 3 == 2){
        out[2] += "#";
    }
    cout << out[0] << endl
    << out[1] << endl
    << out[2] << endl
    << out[1] << endl
    << out[0] << endl;
}