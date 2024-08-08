#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,k;
vector<int> SV;
vector<int> For_R;
//For each
//means [last,this)
string str;
void next(){
    for(int i = For_R.size()-1; i> 0;i--){
        if(For_R[i] < n-i){
            For_R[i]++;
            for(int j = i+1;j<For_R.size();j++){
                For_R[j] = For_R[j-1]+1;
            }
            return;
        }
    }
}
int main(){
    cin >> n >> k >> str;
    for(int i = 0; i <= k+1;i++){
        For_R.push_back(i);
    }
}