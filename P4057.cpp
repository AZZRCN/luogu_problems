#include <bits/stdc++.h>
#include <math.h>
#include <numeric>
using namespace std;

int main(){
    unsigned long long a,b,c,gab,gabc,lab,labc;
    cin >> a >> b >> c;
    lab = a*b/__gcd(a,b);
    cout << lab*c/__gcd(lab,c);
}