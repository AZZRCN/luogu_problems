#include <bits/stdc++.h>
#define unless(...) while(not(__VA_ARGS__))
using namespace std;
class LIS{//uses dp
    public:
    int max_len=0;
    vector<int> nums;//数字
    vector<int> li;//最长数值
    void insert(int O){	
        int i = nums.size();
        nums.push_back(O);
        li.push_back(1);
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                li[i] = max(li[i],li[j]+1);
            }
        }
        max_len = max(max_len,li[i]);
    }
};
int main(){
    int n,t;
    LIS L;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t;
        L.insert(t);
    }
    cout << n - L.max_len;
}