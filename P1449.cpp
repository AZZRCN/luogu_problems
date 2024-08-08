#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<long long> S;
int main(){
    string str;
    cin >> str;
    long long a=0,b=0;
    for(char c:str){
        if(c == '-'|| c == '*' || c== '+' || c == '/'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            if(c == '-'){
            S.push(b-a);
            }
            else if(c == '+'){
                S.push(b+a);
            }
            else if(c == '*'){
                S.push(b*a);
            }
            else{
                S.push(b/a);
            }
            a=0;
            continue;
        }
        if(c == '.'){
            S.push(a);
            a=0;
            continue;
        }
        a = a * 10 + c - '0';
    }
    cout << S.top();
}