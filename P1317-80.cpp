#include <iostream>
#include <bitset>
using namespace std;
short high[10000];
bitset<10000> BS1;//左到右
bitset<10000> BS2;//右到左
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> high[i];
    }
    short maxn = -1;
    for(int i = 2; i <= n; i++){
        maxn = max(maxn, high[i]);
        if(high[i] < maxn){
            BS1[i] = 1;
        }
    }
    maxn = 0;
    for(int i = n - 1; i >= 1; i--){
        maxn = max(maxn, high[i]);
        if(high[i] < maxn){
            BS2[i] = 1;
        }
    }
    maxn = 0;
    for(int i = 1; i <= n; i++){
        BS1[i] = BS1[i] && BS2[i];
    }
    for(int i = 2; i <= n; i++){
        if(BS1[i] > BS1[i - 1]){
            maxn++;
        }
    }
    // printf("maxn:%d", maxn);
    printf("%d", maxn);
}