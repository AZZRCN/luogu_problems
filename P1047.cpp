#include <iostream>
#include <algorithm>
using namespace std;
struct AZZR{
    int b,e;
}T[101];
bool cmp(const AZZR& a, const AZZR& b){
    return a.b<b.b;
}
int main(){
    int l,m,a,b,Te = -1,Tb=-1,ans = 0;
    cin >> l >> m;
    for(int i = 1; i <= m; i++){
        cin >> T[i].b >> T[i].e;
    }
    sort(T+1,T+m+1,cmp);
    for(int i = 1; i <= m; i++){
        if(T[i].b > Te){//新一段
            ans += Te - Tb + 1;
            Te = T[i].e;
            Tb = T[i].b;
        }
        else if (T[i].e > Te)//延续
        {
            Te = T[i].e;
        }
        
    }
    ans += Te - Tb + 1;
    cout << l - ans + 2;
}