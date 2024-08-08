#include <iostream>
using namespace std;
short delta[1002][1002]={};
short map_[1002][1002]={};
int main(){
    int n,m,x1,y1,x2,y2;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        delta[x1][y1]++;
        delta[x1][y2+1]--;
        delta[x2+1][y1]--;
        delta[x2+1][y2+1]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            map_[i][j] = map_[i][j-1] + map_[i-1][j] - map_[i-1][j-1] + delta[i][j];
            cout << map_[i][j] << " ";
        }
        cout << endl;
    }
}