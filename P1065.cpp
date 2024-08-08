#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<vector<bool> > mechine_map;//对于机器i,时间k,[i][k]代表有无安排任务
struct PIIE{
    bool operator()(const pair<int,int>& L, const pair<int,int>& R) const{
        return L.first == R.first && L.second == R.second;
    }
};
struct PIIH{
    int operator()(const pair<int,int>& L)const{
        return hash<int>()(L.first) ^ hash<int>()(L.second);
    }
};
unordered_set<pair<int,int> ,PIIH,PIIE> _set;//同上,调用为set.count(make_pair<i,k>);
int step[21]={};//表示工件的进行状态
int step_machine[21][21]={};//对于工件i,步骤k,[i][k]代表当前步骤的机器编号
int step_cost[21][21]={};//记录花费的时间
queue<int> q;//安排的顺序
int main(){
    ull m,//机器数，工序数
    n,//工件数
    t1,t2;
    cin >> m >> n;
    //这里step暂时借给输入
    for(int i = 1; i<= m * n; i++){
        cin >> t1;
        q.push(t1); 
    }
    for(int i = 1; i <= n; i++){
        cout << "catch1" << endl;
        step[i] = 1;
        for(int j = m; j <= m; j++){
            cin >> t1;//依次表示工件i的工序j使用的机器t
            step_machine[i][j] = t1;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << "catch2" << endl;
        for(int j = m; j <= m; j++){
            cin >> t1;//依次表示工件i的工序j使用的时间t
            step_cost[i][j] = t1;
        }
    }
    int now_object,maxtime=0;
    while(!q.empty()){
        now_object = q.front();
        q.pop();
        //找空闲时间
        int t=0;
        for(int i = 1; (!(t == step_cost[now_object][step[now_object]])) ; i++){t++;if(_set.count(make_pair(step_machine[now_object][step[now_object]],t))){t=0;}}
        for(int i = t - step_cost[now_object][step[now_object]]+1; i <= t; i++){
            _set.insert(make_pair(step_machine[now_object][step[now_object]],i));
        }
        //标记选定时间被选择
        maxtime = max(maxtime,t);
    }
    cout << maxtime;
}