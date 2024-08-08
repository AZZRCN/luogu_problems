#include <iostream>
#include <stack>
#include <list>
#define r return
using namespace std;
list<stack<int> > L;
stack<int> T;
void insert(int n){
    if(L.front().top() >= n){
        L.front().push(n);
        r;
    }
    for(list<stack<int> >::iterator it = L.begin();;it++){
        while(it->top() < n){
            T.push(it->top());
            it->pop();
        }
        it++;
        while(!T.empty()){
            it->push(T.top());
            T.pop();
        }
    }
}
int main(){
    int maxn,t;
    while(! cin.eof){
    }
}