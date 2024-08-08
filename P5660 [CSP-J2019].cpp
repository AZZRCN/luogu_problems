#include <iostream>
#include <string>
int main(){
    int ans = 0;
    std::string s;
    std::cin >> s;
    for(char c:s){
        if(c - 48){
            ans++;
        }
    }
    printf("%d",ans);
}