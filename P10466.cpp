#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<pair<int,int> >upp,low;
set<pair<int,int> >::iterator upper,lower;
int main(){
    int n;
    int a;
    cin >> n;
    cin >> a;
    upp.push_back(make_pair(a,0));
    low.push_back(make_pair(-a,0));
    for(int i = 1; i < n; i++){
        cin >> a;
        upper = upp.upper_bound(make_pair(a,0));
        lower = low.lower_bound(make_pair(-a,0));
        if(upper == upp.end() || lower = low.end()){
            if(upper == upp.end()){
                cout << lower - low.begin() << " " << *lower.first;
            }
            else{
                cout << upper - upp.begin() << " " << *upper.first;
            }
        }
    }

}