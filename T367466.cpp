#include <iostream>
#include <cmath>
using namespace std;
int a[8],b[8];
int main(){
    int n;
    cin >> n;
    int Tans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        Tans += 100 / a[i] * b[i];
    }
    int Au;
    cin >> Au;
    if(Tans >= Au){
        printf("Already Au.");
        return 0;
    }
    Tans = Au - Tans;//还不够的分数
    for(int i = 1; i <= n; i++){
        if((a[i] - b[i]) * 100 / a[i] >= Tans) {
            printf("%.0f\n",ceil(Tans / 100.0 * a[i]));
        }
        else{
            printf("NaN\n");
        }
    }
}