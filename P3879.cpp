#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
vector<unordered_set<string> > V;
int main() {
    int n, t;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {   
        
        V.push_back(unordered_set<string>());
        cin >> t;
        for (int j = 1; j <= t; j++) {
            cin >> str;
            V[i].insert(str);
        }
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (V[j].find(str) != V[j].end()) {
                cout << j + 1 << " "; //输出第j个
            }
        }
        cout << endl;
    }
    //system("pause");
}