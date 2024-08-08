#include <stdio.h>
#define elif else if
static unsigned long long read() {
	signed char w = 0;
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
    unsigned long long T,m,n;
    // cin >> T;
    // scanf("%llu",&T);
    T = read();
    while(T--){
        // cin >> m >> n;
        // scanf("%llu%llu",&m,&n);
        m = read();
        n = read();
        while((m == 2 || m == 1) && n > 0){
            if(m == 2){
                m = 3;
                n--;
            }
            elif(m == 1){
                m = 2;
                n--;
            }
        }
        for(int i = n/32; i > 0; i--){
            m <<= 32;
            m %= 1000000007;
            n -= 32;
        }
        m <<= n;
        // cout << m%1000000007 << endl;
        printf("%llu\n",m%1000000007);
    }
}