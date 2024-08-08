#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a=1,b=1;
    while(a != 0&& b != 0){
        cin >> a >> b;
        //计算[sqrt(a),sqrt(b)]中的整数数量
        cout << 
            floor(sqrt(b))-
            ceil(sqrt(a))+1
             << endl;
    }
}