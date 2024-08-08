#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    deque<pair<int,int> > l;
    int O1,O2;
    for(int i = 1; i <= n; i++){
        cin >> O1 >> O2;
        l.push_back(make_pair(O1,O2));
    }
    sort(l.begin(),l.end(),greater_equal<pair<int,int> >());
    int cur = 0,ans=0;

    while(!l.empty()){
        O1 = l.begin()->first;
        O2 = l.begin()->second;
        l.pop_front();
        cur = 0;
        while((cur < l.size())){
            if(l[cur].first <= O1 && l[cur].second <= O2){
                O1 = l[cur].first;
                O2 = l[cur].second;
                l.erase(l.begin()+cur);
                continue;
            }
            cur++;
        }
        ans++;
    }
    cout<<ans;
}