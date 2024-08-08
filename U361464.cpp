#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n+1];
    int b[n+1];
    bool invalidcolor[n+1] = {};
    int invalidcolors = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(invalidcolor[a[i]] == false){
            invalidcolors++;
        }
        invalidcolor[a[i]] = true;
    }
    if(invalidcolors < k){
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int colors[invalidcolors+1]= {};//有效的颜色
    int cura = 1;//记录目前到哪了(colors)
    int curb = 1;//记录探测的位置(invalidcolor)
    while(cura <= n){
        if(invalidcolor[curb] == true){
            colors[cura] = curb;
            cura++;
        }
        curb++;
    }//到了现在,colors记录的是所有有效的颜色(从小到大)
    int color[k+1];//记录颜色,共k个,上升序列
    for(cura = 1; cura <= k; cura++){
        color[cura] = colors[cura];
    }
}