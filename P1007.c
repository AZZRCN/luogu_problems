#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
void write(unsigned short x) {
	static unsigned char sta[35];
	unsigned short top = 0;
	do {sta[top++] = x % 10, x /= 10;} while (x);
	while (top) putchar(sta[--top] | 0x30);  // 48 是 '0'
}
static unsigned short read() {
	unsigned short n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 0x9) {ch = getchar();}
	while ((ch ^ '0') < 0xA) {n = n * 0xA + (ch ^ 0x30);ch = getchar();}return n;
}
int main(){
    unsigned short t;
    const unsigned short L = read() +1;
    unsigned short minn=0,maxn = 0;
    for(unsigned short i = read();i;i--){
        t = read();
        if((t<<1) < L){//在一半以前
            maxn = max(maxn,L-t);
            minn = max(minn,t);
        }
        else{
            maxn = max(maxn,t);
            minn = max(minn,L-t);
        }
    }
    write(minn),putchar(' '),write(maxn);
}