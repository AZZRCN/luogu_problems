#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
void solve1(int n){
    string str;
    while(n){
        str.push_back(n%26?n%26+'A'-1:'Z');
        //26 ->Z
        //
        n /= 26;
    }
    reverse(str.begin(), str.end());
    //printf("solve1:");
    cout << str;
}
void solve2(string s){
    //cout << "solve2:";
    int t = 0;
    for(int i = 0 ; i < s. length() ; i++){
        t = t * 26 + s[i] - 'A' + 1;
    }
    cout << t << "\n";
}
int main(){
    int n,a,b,cur;
    string c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        a = 0;
        b = 0;
        c.clear();
        if(str[0] == 'R'){
            cur = 1;
            //printf("A\n");
            while(str[cur] >= '0' && str[cur] <= '9'){
                a = a * 10 + (str[cur] - '0');
                cur++;
            }
            // printf("A1\n");
            cur++;
            while(str[cur] >= '0' && str[cur] <= '9' && cur < str.length()){
                b = b * 10 + (str[cur] - '0');
                cur++;
            }
            // printf("A2\n");
            solve1(b);
            cout << a << "\n";
        }
        else{
            cur = 0;
            // printf("B\n");
            while(str[cur] >= 'A' && str[cur] <= 'Z'){
                c.push_back(str[cur]);
                cur++;
            }
            // printf("B1\n");
            //cur --;
            for(;cur<str.length();cur++){
                a = a * 10 + str[cur] - '0';
            }
            // printf("B2\n");
            cout << "R" << a << "C";
            solve2(c);
            cout << endl;
        }
    }
}