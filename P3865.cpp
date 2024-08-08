#include <bits/stdc++.h>
using namespace std;
#define u unsigned
#define ll long long
#define ull u ll
u ll st[100005][20];
u ll n,m;
u ll a[100005];
static unsigned long long read() {
	unsigned long long n = 0;
	unsigned ll ch = getchar();
	while ((ch ^ '0') > 9) {
		ch = getchar();
	}
	while ((ch ^ '0') < 0xA) {
		n = n * 0xA + (ch^'0');
		ch = getchar();
	}
	return n;
}
static inline void write(unsigned long long x) {
	static unsigned char sta[35];
	short top = 0;
	do {sta[top++] = x % 10, x /= 10;} while (x);
	while (top) putchar(sta[--top] ^ 0x30);  // 48 是 '0'
}
void init()
{
    for (u i = 1; i < n; i++)
    {
        st[i][0] = a[i];
    }
    for (u j = 1; (1 << j) < n; j++)
    {
        for (u i = 1; i + (1 << j) - 1 < n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
unsigned long long search(unsigned long long l,unsigned long long r){
    unsigned char k = (31 - __builtin_clz(r-l+1));
    return max(st[l][k], st[r-(1<<k)+1][k]);
}
int main()
{
    n = read();
    n++;
    m = read();
    for (int i = 1; i < n; i++)
    {
        a[i]=read();
    }
    init();
    for(int i = 1; i <= m; i++){
        n = read();
        write(search(n, read()));
        putchar('\n');
    }
}