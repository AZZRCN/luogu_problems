#include <stdio.h>
#include <stdbool.h>
int main(){
	bool w = false;
	int a = 0;
	register unsigned char ch = getchar();
	int b = 0;
	static short sta[10];
	if (ch == '-') {w = true;ch = getchar();}
	while ((ch ^ '0') < 0xA) {
		a = a * 0xA + ch - 0x30;
		ch = getchar();
	}
	if (w) {a=-a;}
	w = false;
	ch = getchar();
	if (ch == '-') {w = true;ch = getchar();}
	while ((ch ^ '0') < 0xA) {
		b = b * 0xA + ch - 0x30;
		ch = getchar();
	}
	if (w) {b=-b;}
	a=a+b;
	if ((a>>31)) {
		putchar('-');
		a = (~(a)+1);
	}
	b=0;
	do {
		sta[b++] = a % 10;
		a /= 10;
	} while (a);
	while (b) putchar(sta[--b] + 48);  // 48 是 '0'
}