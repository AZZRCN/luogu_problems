#include <stdio.h>
#define ull unsigned long long
ull num[101]={};
static ull read() {
	ull n = 0;
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
    ull sum = 0,ans=0;
    ull n = read();
    for(ull i=0;i<n;i++){
        num[i] = read();
        sum += num[i];
    }
    sum /= n;
    for(ull i=0;i<n;i++){
        if(num[i] != sum){
            num[i+1] += num[i] - sum;
            num[i] = sum;
            ans++;
        }
    }
    write(ans);
}