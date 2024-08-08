#include <bits/stdc++.h>
using namespace std;
class LIS{
    public:
    size_t max_len=0;
    std::stack<int> s;//大顶
    LIS(void){max_len=0;}
    void insert(int O){
        while(!s.empty() && s.top() >= O){
            s.pop();
        }
        s.push(O);
        max_len = max(max_len,s.size());
    }
};
int main(){
    int n,t;
    LIS L;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t;
        L.insert(t);
    }
    cout << L.max_len;
}