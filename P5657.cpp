#include <bits/stdc++.h>
using namespace std;
bitset<64> BS;
static unsigned long long read() {
	unsigned long long n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 9) {
		ch = getchar();
	}
	while ((ch ^ '0') < 0xA) {
		n = n * 0xA + ch - 0x30;
		ch = getchar();
	}
	return n;
}
int main(){
    unsigned long long m=read(),n=read();
    BS = (n^(n>>1));
    for(int i = m-1; i >=0; i--){
        cout << BS[i];
    }
}