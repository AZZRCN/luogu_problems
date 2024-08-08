#include <iostream>
using namespace std;
int minn = 1e7;
int S[11],B[11];
int n;
void dfs(int s,int b,int deepth,int choosen){
    if(deepth == n+1){
        if(choosen){minn = min(minn,abs(s-b));}
        return;
    }
    dfs(S[deepth]*s,    B[deepth]+b,    deepth+1,choosen+1);
    dfs(s,              b,              deepth+1,choosen);
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> S[i] >> B[i];
    dfs(1,0,1,0);
    cout << minn;
}