#include <bits/stdc++.h>
#include <map>
using namespace std;
// struct AZZR_NODE{
//     int x, y;
//     bool operator==(const AZZR_NODE& other) const{
//         return x == other.x && y == other.y;
//     }
// };
// map<AZZR_NODE,int> moved;//第一个目前编号(x,y),第二个原始编号(int)
map<int,int> moved;//当前,原始
int n,m,q;
void slove(int x,int y){//行,列,输入行合列
    int xy = (x-1)*m+y;
    for(auto k:moved){
        if(k.first == xy){//找到了
            printf("%d",k.second);
            
        }
    }
}
int main(){
    
    
}