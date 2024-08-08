#include <iostream>
using namespace std;
short map[51][51] = {};
int main(){
    int m;//行数
    int n;//列数
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <=n; j++){
            cin >> map[i][j];
        }
    }
}