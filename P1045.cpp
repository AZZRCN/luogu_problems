#include <bits/stdc++.h>
#define head1
#include "..\..\VSOT\console\head1.cpp"
using namespace std;
unsigned long long length(unsigned long long x){
    return log10l(x)+1;
}
unsigned long long length_base2(unsigned long long n){
    return (unsigned long long)(log10l(2)*n+1);
}
int main(){
    cout << length_base2(3);
}