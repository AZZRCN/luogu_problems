#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define u unsigned
#define N 100005
ll n, m;
ll a[N];
int l = 0, r = 1e9;
//二分找答案
bool check(int v/*分段数值的大小*/){
    int cnt = 1, sum = 0;
    for(int i = 1; i <= n; i++){
        if(sum+a[i] <= v){
            sum += a[i];
        }
        else{
            sum = a[i];
            cnt++;
        }
    }
    return cnt <= m;
}
int main(){
    ll mx=0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];mx = max(a[i],mx);
    }
    l=mx;
    while(l<r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l;
}