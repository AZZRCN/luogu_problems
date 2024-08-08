#include <iostream>
#include <bitset>
using namespace std;
bitset<100> BS[100];
void set(int x, int y){
    if(x < 0 || x >= 100 || y < 0 || y >= 100) return;
    BS[y][x] = 1;
}
void fill1(int x, int y){
    set(x - 1 , y - 1);
    set(x + 1 , y - 1);
    set(x - 1 , y + 1);
    set(x + 1 , y + 1);
    set(x - 2, y);
    set(x - 1, y);
    set(x + 1, y);
    set(x + 2, y);
    set(x, y - 2);
    set(x, y - 1);
    set(x, y + 1);
    set(x, y + 2);
    set(x,y);
}
void fill2(int x, int y){
    set(x - 2 , y - 2);
    set(x - 1 , y - 2);
    set(x , y - 2);
    set(x + 1 , y - 2);
    set(x + 2 , y - 2);
    set(x - 2 , y - 1);
    set(x - 1 , y - 1);
    set(x , y - 1);
    set(x + 1 , y - 1);
    set(x + 2 , y - 1);
    set(x - 2 , y);
    set(x - 1 , y);
    set(x , y);
    set(x + 1 , y);
    set(x + 2 , y);
    set(x - 2 , y + 1);
    set(x - 1 , y + 1);
    set(x , y + 1);
    set(x + 1 , y + 1);
    set(x + 2 , y + 1);
    set(x - 2 , y + 2);
    set(x - 1 , y + 2);
    set(x , y + 2);
    set(x + 1 , y + 2);
    set(x + 2 , y + 2);
}
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int x,y;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        fill1(x,y);
    }
    for(int i = 1; i <= k; i++){
        cin >> x >> y;
        fill2(x,y);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            if(BS[i][j] == 0){cnt++;}
            //cout << BS[i][j];
        }
        //cout << endl;
    }
    cout << cnt << endl;
}