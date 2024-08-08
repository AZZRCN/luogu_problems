#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void fillPrism(std::vector<int>& pri,int N,unordered_map<int,bool>&out) {
	std::vector<bool> not_prime;
	not_prime.clear();
	not_prime.resize(static_cast<std::vector<bool, std::allocator<bool>>::size_type>(N) + 1, 0);
	pri.push_back(2);
	not_prime[4] = true;
	for (int i = 3; i <= N; i += 2) {
		if (!not_prime[i]) {
			pri.push_back(i);
		}
		for (int j : pri) {
			if ((i * j > N) ) { break; }
			not_prime[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(i) * j] = true;
		}
	}
    out.clear();
    for(auto k:pri){
        out.insert(make_pair(k,true));
    }
}
vector<int> prism_list;
unordered_map<int,bool> slove_map;
int main(){
    fillPrism(prism_list, 1000000,slove_map);
    int n=1;
    while(n){
        A:
        cin >> n;
        for(int i = 3; i < n-1; i++){
            if(slove_map[i] && slove_map[n-i]){
                printf("%d = %d + %d\n",n,i,n-i);
                goto A;
            }
        }
        if(n != 0 )
        {printf("Goldbach's conjecture is wrong\n");}
    }
}