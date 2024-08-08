#include <stdio.h>
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
void write(unsigned long long x) {
  static unsigned long long sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
int main(){
    unsigned long long ans = 0,n,x,t1,t2;
    n = read();
    x = read();
    t2 = read();
    if(t2 > x){
        ans += t2-x;
        t2 = x;
    }
    for(unsigned long long i = 1; i < n; i++){
        t1 = t2;
        t2 = read();
        if(t2 + t1 > x){
            ans += t2 + t1-x;
            t2 = x - t1;
        }
    }
    // cout << ans;
    write(ans);
}