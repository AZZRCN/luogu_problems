#include <iostream>
#include <stack>
using namespace std;
int delta[1000002]={};
class info{
    public:
    int start,end,num;
    info(int S,int E,int N){
        start = S;
        end = E;
        num = N;
    }
    void redo(){
        delta[start] += num;
        delta[end+1] -= num;
    }
}
stack<info> STACK;
int main(){
    
}