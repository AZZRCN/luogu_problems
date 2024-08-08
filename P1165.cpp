#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
unordered_map<int,int> is_del;
priority_queue<int> max_priority;
stack<int> sta;
int main(){
    freopen("out","w",stdout);
    int n,a,b;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(a == 2){
            cout << (max_priority.empty()?0:max_priority.top()) << endl;
        }
        if(a == 1){
            //弹出最大
            if(max_priority.top() == sta.top() || (is_del.count(max_priority.top()) && is_del[max_priority.top()])){
                sta.pop();
                max_priority.pop();
                while(not is_del.empty() && is_del[max_priority.top()] > 0){
                    is_del[max_priority.top()]--;
                    max_priority.pop();
                }
            }//弹出其他
            else{
                //is_del添加
                //其余不动
                if(is_del.count(sta.top())){
                    is_del[sta.top()]++;
                }
                else{
                    is_del.insert(make_pair(sta.top(),1));
                }
                sta.pop();
            }
        }
        if(a == 0){
            cin >> b;
            sta.push(b);
            max_priority.push(b);
        }
    }
}