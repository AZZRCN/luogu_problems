#include <iostream>
#include <unordered_map>
#include <bits/basic_string.h>
std::unordered_map<std::__cxx11::basic_string<char>,bool> map;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // std::cout.tie(0);
    int n,cnt=0;
    std::__cxx11::basic_string<char> str;
    std::cin >> n;
    for(int i = 1; i <= n;i++){
        std::cin >> str;
        if(map.count(str) == 0){
            cnt++;
            map.insert(make_pair(str,true));
        }
    }
    // std::cout << cnt;
    printf("%d",cnt);
}