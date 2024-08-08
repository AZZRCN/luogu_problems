// #include <iostream>
// #include <string>
// #include <bitset>
// using namespace std;
// int main(){
//     int x1,x2,y1,y2,Ex = 0,Ey=0,x,y;
//     scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
//     x = max(abs(x1),abs(x2));
//     y = max(abs(y1),abs(y2));
//     while(x){
//         Ex++;
//         x >> 1;
//     }
//     while(y){
//         Ey++;
//         y >> 1;
//     }
//     if(Ex + Ey >= 32){
//         printf("long long int");
//     }
//     else{
//         printf("int");
//     }
// }
#include <iostream>
using namespace std;

int main() {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    long long x = max(abs(x1), abs(x2));
    long long y = max(abs(y1), abs(y2));
    if (x * y > 2147483647) {
        cout << "long long int" << endl;
    } else {
        cout << "int" << endl;
    }
    return 0;
}