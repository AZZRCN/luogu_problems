#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int cur = 0;//与unnormal一起使用
struct AZZR{
    int x,y,length;//x横,y竖,length长度
    bool operator==(const AZZR& other) const{
        return x == other.x && y == other.y && length == other.length;
    }
}normal[2001];//,unnormal[2000];//正常三角形,特殊判断
bool cmp(const AZZR& a,const AZZR& b){
    if(a.y != b.y){
        if(a.x != b.x){
            return a.length > b.length;
        }
        return a.x < b.x;
    }
    return a.y > b.y;
}
//某个点在三角形内
//x<point.x<x+length&&y<point.y<y.length&&point.x-x+point.y-y< length
//-5,-3,6;-4,-1 accept
bool point_in(const AZZR&sj,const AZZR& p){
    return sj.x < p.x &&
    p.x < sj.x + sj.length &&
    sj.y < p.y &&
    p.y < sj.y + sj.length &&
    p.x - sj.x + p.y - sj.y < sj.length;
}
//计算重叠
double suan(AZZR a,AZZR b){
    AZZR T[6] = {a,a,b,b};
    T[0].x += a.length;
    T[1].y += a.length;
    T[2].x += b.length;
    T[3].y += b.length;
    if(
    point_in(b,a) +
    point_in(a,b) +
    point_in(T[0],b) +
    point_in(T[1],b) +
    point_in(T[2],a) +
    point_in(T[3],a)
    ){
    }
    else{
        return 0;
    }//不包含
    /*if((point_in(b,a) &
    point_in(b,T[0]) &
    point_in(b,T[1]) )|
    (point_in(a,b) &
    point_in(a,T[2]) &
    point_in(a, T[3]))){//完全覆盖
        return pow(min(a,b).length,2);
    }
    if(a.x == b.x){
        return 
    }*/
    //都在右上方
    double TD;
    if(a.x >= b.x & a.y >= b.y){
        TD = min(a.length,b.length - a.x + b.x - a.y + b.y);
        return TD * TD;
    }
    if(a.x <= b.x & a.y <= b.y){
        TD = min(b.length,a.length - b.x + a.x - b.y + a.y);
        return TD*TD;
    }
    //右下面
    if(a.x <= b.x & a.y >= b.y){
        TD = b.length - a.y - b.y;
        return TD * TD;
    }
    if(a.x >= b.x & a.y <= b.y){
        TD = a.length - b.y - a.y;
        return TD * TD;
    }
    return 0;
}
//特殊说明:请在最后输出时除以2
int main(){
    int n;
    cin >> n;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> normal[i].x >> normal[i].y >> normal[i].length;
    }
    sort(normal+1,normal+n+1,cmp);
    AZZR T = normal[1];
    int T2 = 0;
    for(int i = 2; i <= n; i++){
        if(T == normal[i]){
            T2 += normal[i].length;
            normal[i].length = -1;
        }
        else{
            ans += T.length * T.length;
            T =normal[i];
        }
        //ans += normal[i].length * normal[i].length;
        //计算正方形
    }
    if(normal[n].length == -1){
        ans += T2 * T2;
    }
    if(n == 1){
        ans = normal[1].length * normal[1].length;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(normal[i].length == -1 || normal[j].length == -1){
                continue;
            }
            ans -= suan(normal[i],normal[j]) ;
        }
    }
    printf("%.1f", ans /2.0);
}