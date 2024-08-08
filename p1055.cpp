#include <string>
#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int per = 1,sum=0,back,cur=0;
    for(auto c:str){
            cur++;
        if(c != '-' && cur <12){
            sum += (c-'0')*per;
            per++;
        }
    }
    if(str.back() == 'X'){
        back = 10;
    }
    else{
        back = str.back()-'0';
    }
    sum %=11;
    str.pop_back();
    if(sum == back){
        cout << "Right";
    }
    else{
        str.push_back((sum == 10)?'X':('0'+sum));
        cout << str;
    }
}