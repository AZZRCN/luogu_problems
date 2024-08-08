#include <bits/stdc++.h>
using namespace std;
string out;
map<char,int> map_={
    {'+',0},{'-',0},
    {'*',1},{'/',1},
    {'^',2},
    {'(',3}
};//优先级
stack<char> op_stack;
bool is_digit(unsigned char c){
    return (c^'0')<0xA;
}
void test(string str,int cur){
    int cur2 = str.find(')',cur);
    op_stack.push_back(3);

}
int main(){
    string str;
    cin >> str;
    for(char c:str){
        if(is_digit(c)){
            out.push_back(c);
        }
        else{
            if(map_[c] <= op_stack.top()){
            }
        }
    }
}