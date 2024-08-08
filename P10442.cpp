#include <iostream>
#include <string>
using namespace std;
int s[26] = {};
int s2[26] = {};
int ans;
int main() {
    string str;
    cin >> str;
    for (char k : str) {
        s[k - 'a']++;
    }
    cin >> str;
    for (char k : str) {
        s2[k - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        ans += min(s[i], s2[i]);
    }
    cout << ans;
}