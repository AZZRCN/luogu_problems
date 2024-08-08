#include <bits/stdc++.h>
using namespace std;
int n,//数量
h,//高度
r;//半径
class hole{
    public:
    int x,y,z;
    hole(void){;};
    hole(int O1,int O2,int O3){x=O1;y=O2;z=O3;};
    bool operator()(const hole& O){
        return(sqrt(pow(x+O.x,2)+pow(y+O.y,2)+pow(z+O.z,2))<=r);
    }
}
class holes{
    public:
    vector<hole> hv;
    void insert(hole O){
        for(hole i : hv){
            if(i(O)){
                hv.push_back(O);
                return;
            }
        }
    }
}
vector<holes> v;
int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> n >> h >> r;

    }
}