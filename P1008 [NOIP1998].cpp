#include <iostream>
#include <string>
using namespace std;
bool slove(string a){
    for(auto k:a){
        if(k == '0'){
            return false;
        }
    }
    for(int i = 0; i < a.length(); i++){
        for(int j = i + 1; j < a.length(); j++){
            if(a[i] == a[j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int i,j,k;//3,1,2
    string a;
    for(i = 576; i <= 987; i += 3){
        j = i / 3;
        k = j * 2;
        a = to_string(j) + to_string(k) + to_string(i);
        if(slove(a)){
            printf("%d %d %d\n", j,k,i);
        }
    }
}