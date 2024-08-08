#include <stdio.h>
#include <algorithm>
#define elif else if
int main(){
    unsigned long long l[3];
    scanf("%lld%lld%lld",&l[0],&l[1],&l[2]);
    std::sort(l,l+3);
    if(l[0] + l[1] <= l[2]){
        puts("Not triangle");
        return 0;
    }
    const unsigned long long t = l[0] * l[0] + l[1] * l[1];
    const unsigned long long t2 = l[2] * l[2];
    if(t == t2){
        puts("Right triangle");
    }
    elif(t > t2){
        puts("Acute triangle");
    }   
    else{
        puts("Obtuse triangle");
    }
    if(l[0] ==l[1] || l[0] ==l[2] || l[1] ==l[2]){
        puts("Isosceles triangle");
    }
    if(l[0] == l[1] && l[1] == l[2]){
        puts("Equilateral triangle");
    }
}