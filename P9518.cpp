#include <bits/stdc++.h>
using namespace std;
// deque<string> dq;
// vector<string>dq;
// list<string> dq;
queue<string>dq;
// deque<string> playing;
string playing[2];
unordered_set<string> people;
unordered_set<string> is_del;
int main(){
    // freopen("out","w",stdout);
    string ope,name;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ope;
        if(ope == "start"){
            for(int i = 0; i<2&&(not playing[i].empty());i++){
            // while(not playing.empty()){//清台
                dq.push(playing[i]);
                playing[i].clear();
            }
            if(dq.empty()){//没有人
                puts("Error");
                continue;
            }
            else{//放到机子上
                if(dq.size() > 1){
                    while(is_del.count(dq.front())){
                        is_del.erase(dq.front());
                        dq.pop();
                    }
                    cout << dq.front() << " ";
                    playing[0] = dq.front();
                    dq.pop();
                    while(is_del.count(dq.front())){
                        is_del.erase(dq.front());
                        dq.pop();
                    }
                    cout << dq.front() << endl;
                    playing[1] = dq.front();
                    dq.pop();
                    continue;
                }
                else{
                    while(is_del.count(dq.front())){
                        is_del.erase(dq.front());
                        dq.pop();
                    }
                    cout << dq.front() << endl;
                    playing[0] = dq.front();
                    dq.pop();
                }
            }
        }
        else if(ope == "arrive"){
            cin >> name;
            if(people.count(name)){
                puts("Error");
            }
            else{
                dq.push(name);
                people.insert(name);
                puts("OK");
            }
        }
        else{
            cin >> name;
            if(people.count(name)){
                if(playing[0] == name || playing[1] == name){
                puts("Error");
                }
                else{
                    people.erase(name);
                    while(is_del.count(dq.front())){
                        is_del.erase(dq.front());
                        dq.pop();
                    }
                    if(name != dq.front()){
                        is_del.insert(name);
                    }
                    else{
                        dq.pop();
                    }
                    puts("OK");
                }
            }
            else{
                puts("Error");
            }
        }
    }
}