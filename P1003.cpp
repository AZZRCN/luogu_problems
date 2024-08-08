#include<iostream>
using namespace std;
//int a[100005],b[100005],g[100005],k[100005];
struct P1003
{
    int a,b,g,k;
}res[100001],t;

int main(){
    int n,x,y;
    //scanf("%d",&n);
    cin >> n;
    for(int i = 1; i <= n; i++){
        //cin >> a[i] >> b[i] >> g[i] >> k[i];
        scanf("%d%d%d%d",&res[i].a,&res[i].a + 1,&res[i].a + 2,&res[i].a + 3);
    }
    cin >> x >> y;
    for(int i = n; i >= 1; i--){
        t = res[i];
        if(t.a <= x & t.a+t.g >= x & t.b <= y & t.b+t.k >= y){
            printf("%d",i);
            return 0;
        }
    }
    cout << -1;
}