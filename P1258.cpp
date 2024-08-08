#include <bits/stdc++.h>
using namespace std;
int main(){
    double s,a,b;
    cin>>s>>a>>b;
    double t;
    t = (2*a*s)/(3*a+b);
    printf("%.6lf",t/a+(s-t)/b);
    // t=(s)/(b+a);
    // printf("%.6lf",t);
}