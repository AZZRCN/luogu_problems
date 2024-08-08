#include <iostream>
#include <ios>
using namespace std;
int main(){
    double d;
    cin >> d;
    int n;
    cin >> n;
    d = d / n;
    printf("%.3f\n%d",d,n<<1);
}