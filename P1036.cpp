#include <iostream>
using namespace std;
#define r(...) return __VA_ARGS__
#define ull unsigned long long
#define u unsigned
ull ans=0;
ull num[25];
ull n,k;
bool isPrime(ull n) {
	if (n < 2 || (!(n&1))) r(false);
	for (ull i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			r(false);
		}
	}
	r(true);
}
//选择数量，下一个深度，累加和
void dfs(u deepth,ull choosen,ull sum){
    if(choosen == k){
        if(isPrime(sum)) {
            ans++;
            // cout << sum << endl;
        }
        r();
    }
    if(deepth == n+1){
        r();
    }
    dfs(deepth+1,   choosen+1,  sum+num[deepth]);
    dfs(deepth+1,   choosen,    sum);
}
int main(){
    cin >> n >> k;
    for(ull i = 1; i <= n; i++){
        cin >> num[i];
    }
    dfs(1,0,0);
    cout << ans;
}