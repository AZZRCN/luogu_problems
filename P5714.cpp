#include <bits/stdc++.h>
#define elif else if
using namespace std;

int main() {
    double m,h;
    cin >> m >> h;
    m = (m / (h*h));//NOW IS BMI
    if(m < 18.5){
        cout << "Underweight" << endl;
    }
    elif(m<24){
        cout << "Normal" << endl;
    }
    else{
        cout << m << endl << "Overweight" << endl;
    }
}