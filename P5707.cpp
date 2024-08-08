#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int s,v,t = 1910,t2;
    cin >> s >> v;
    t2 = s / v;
    if(s%v){t2++;}
    t -= t2;
    t %= 1440;
    s = t / 60;
    v = t % 60;
    printf("%02d:%02d",s,v);
}