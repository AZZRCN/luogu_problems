#include <vector>
#include <iostream>
struct tap{
    int t;
    int price;
};
std::vector<tap> vec;
void add(int begintime,int price){
    tap addn = {begintime,price};
    vec.push_back(addn);
}
int find(int price){
    int cur;
    for(cur = 0; cur < vec.size(); cur++){
        if(vec[cur].price >= 0){
            return cur;
        }
    }
    return -1;
}
void update(int t){
    while(!vec.empty() && vec[0].t + 45 >= t){
        vec.erase(vec.begin());
    }
}
int main(){
    int n,i,j,ans = 0;
    int k;//k equals time
    std::cin >> n;
    while(n){
        std::cin >> i >> j >> k;
        if(i == 0){
            add(k,j);
            ans += k;
        }
        else{
            update(k);
            if(find(j) != -1){
                vec.erase(vec.begin() + find(j));
            }
            else{
                ans += j;
            }
        }
    }
    std::cout << ans;
}