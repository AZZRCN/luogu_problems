#include <iostream>
#include <algorithm>
using namespace std;
//min(t1,t1+t2),min(t2,t2+t1)
struct pos{
    int value,position;
    pos(int O1,int O2){
        value = O1;
        position = O2;
    }
    pos(){
        value = position = 0;
    }
};
bool cmp(const pos &t1,const pos& t2){
    return t1.value < t2.value;
}
pos T[1001];
int main(){
    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> T[i].value;
        T[i].position = i;
    }
    sort(T+1,T+n+1,cmp);
    for(int i = 1; i <= n; i++){
        cout << T[i].position << " ";
        ans += (n - i) * T[i].value;
    }
    // cout << "\n" << ((1.0)*ans/n) << endl;
    printf("\n%.2lf",((1.0)*ans/n));
}