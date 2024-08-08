#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> s;
stack<int> S1;
stack<int> S2;
string str;
//先输入S2(等候区)
//输入t,如果不是s1队头,那么从s2一直拿,直到s2为空或者s1队头
int main(){
    freopen("out","w",stdout);
    int n,t;
    int m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        mark_1:
        while(not S1.empty()) S1.pop();
        while(not S2.empty()) S2.pop();
        cin >> m;
        for(int j = 1; j<= m; j++){
            cin >> t;
            S2.push(t);
        }
        for(int j = 1; j<= m; j++){
            cin >> t;
            while(S2.empty() || (S2.top() != t && not S1.empty())){
                S2.push(S1.top());
                S1.pop();
            }
            if(S1.empty()){
                cout << "No" << endl;
                getline(cin,str);
                i++;
                goto mark_1;
            }
        }
        cout << "Yes" << endl;
    }
}//HIZI