#include <string>
#include <iostream>
using namespace std;
unsigned char num[71]={};

unsigned char num2[71]={};
void slove(int n){
    int carry = 0,t;
    for(int i = 70; i ; i--){
        t = num2[i]*n+carry;
        num2[i] = t%10;
        carry = t/10;
    }
}
void add(){
    int carry = 0,t;
    for(int i = 70; i ; i--){
        t = num[i]+num2[i]+carry;
        carry = t/10;
        num[i] = t%10;
    }
}
void print(){
    //for(auto k:num2){
    //    putchar(k+'0');
    //}
    //putchar('\n');
    int i = 0;
    for(;i<=70;i++){
        if(num[i]!=0){break;}
    }
    for(;i<=70;i++){
        putchar(num[i]+'0');
    }
}
int main(){
    int n=11;
    cin >> n;
    num2[70]=1;
    for(int i = 1; i <= n; i++){
        slove(i);
        add();
    }
    print();
}