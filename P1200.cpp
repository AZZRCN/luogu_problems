#include <string>
#include <iostream>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int a_result = 1;
    int b_result = 1;
    for(int i = 0 ; i < a.length() ; i++){
        a_result = ((a[i] - 'A' + 1) * a_result) % 47;
    }
    for(int i = 0 ; i < b.length() ; i++){
        b_result = ((b[i] - 'A' + 1) * b_result) % 47;
    }
    // printf("%d\n%d",a_result,b_result);
    a_result == b_result ? printf("GO") : printf("STAY");
}