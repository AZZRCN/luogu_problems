#include <stdio.h>
// using namespace std;
int ans[10]={};
class Number{
    public:
    int n[10]={0,0,0,0,0,0,0,0,0,0};
    int length = 9;
    void operator++(){for(int i = 9; i ; i--){if(n[i] != 9){n[i]++;length = length>i?i:length;break;}else{n[i] = 0;}}}
    void update(){for(int i = length+1; i < 10; i++){ans[n[i]]++;}}
    void operator=(int a){for(; a; length--){n[length] = a % 10;a /= 10;}}
};
int main(){
    Number _slove;
    int n,m;
    scanf("%d %d",&n,&m);
    _slove = n;
    for(int i = m-n+1;i;i--){
        _slove.update();
        _slove.operator++();
    }
    for(int i = 0; i < 10; i++){
        printf("%d ",ans[i]);
    }
}