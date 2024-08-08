#include <queue>
#include <stdio.h>
using namespace std;
priority_queue<unsigned int ,vector<unsigned int>,greater<unsigned int> > Q;
static unsigned int read() {
	unsigned int n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 0x9) {ch = getchar();}
    while ((ch ^ '0') < 0xA) {n = n * 0xA + ch - 0x30;ch = getchar();}return n;
}
void write(unsigned long long x) {
	static unsigned char sta[35];
	short top = 0;
	do {sta[top++] = x % 10, x /= 10;} while (x);
	while (top) putchar(sta[--top] ^ 0x30);  // 48 是 '0'
}
int main(){
    unsigned int n,ans = 0;
    unsigned int t = read();
    while(t--){Q.push(read());}
    n = Q.size()-1;
    while(n--){
        t = Q.top();
        Q.pop();
        t += Q.top();
        Q.pop();
        ans += t;
        Q.push(t);
    }
    write(ans);
}