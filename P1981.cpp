#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> S;
bool is_digit(unsigned char c) {
    return (c ^ '0') < 0xA;
}
int main() {
    string s;
    cin >> s;
    bool flag = false;
    unsigned long long t = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {//输入数字
            t = t * 10 + s[i] - '0';
            flag = false;
            continue;
        }
        if (not flag) {
            S.push(t);
            t = 0;
        }
        if (s[i] == '*') {
            for (i++; i < s.length(); i++) {
                if (isdigit(s[i])) {
                    t = t * 10 + s[i] - '0';
                    continue;
                }
                else {
                    break;
                }
            }
			//cout << t << " " << S.top() << endl;
            S.top() *= t;
            S.top() %= 10000;
            //cout << S.top() << endl;
            t = 0;
            i--;
            flag = true;
            continue;
        }
    }
    S.push(t);
    int sum = 0;
    while (not S.empty()) {
        sum += S.top();
        S.pop();
        sum %= 10000;
    }
    cout << sum%10000;
    system("pause");
}