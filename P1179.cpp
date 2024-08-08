#include <iostream>
using namespace std;
// bool is_bin(int n){
//     while(n){
//         if(n % 10 == 2){
//             return true;
//         }
//         n /= 10;
//     }
//     return false;
// }
int add_bin(int n){
    int ans = 0;
    while(n){
        if(n%10 == 2){
            ans++;
        }
        n /= 10;
    }
    return ans;
}
int main(){
    int L,R;
    cin >> L >> R;
    int ans= 0;
    // for(int i = L; i <= R; i++){
    //     // printf("%d\n",is_bin(i));
    //     if(is_bin(i)){
    //         ans++;
    //         printf("%d\n",i);
    //     }
    //     // ans += is_bin(i);
    // }
    for(int i = L; i <= R; i++){
        ans += add_bin(i);
    }
    printf("%d",ans);
}