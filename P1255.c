#include <stdio.h>
static unsigned long long read() {
	unsigned long long n = 0;
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
    unsigned long long a=1,b=1,c,n=read();
    while(n--){
        c=a+b;
        a=b;
        b=c;
    }
    write(a);
    write(0x7fffffffffffffff);
}