#include <iostream>
#include <math.h>
using namespace std;
int main(){
    double a,b,c,p;
    cin >> a >> b >> c;
    p = (a+b+c)/2;
    p = p*(p-a)*(p-b)*(p-c);
    p = sqrt(p);
    printf("%.1f",p);
}