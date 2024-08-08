#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int Ldp[102],Rdp[102],h[102];
int n;
void deal()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (h[j] < h[i])
				Ldp[i] = max(Ldp[i], Ldp[j] + 1);
}
void deal2()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (h[j] < h[i])
				Rdp[i] = max(Rdp[i], Rdp[j] + 1);
}
int main(){
    // freopen("in","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    deal();
    reverse(h+1,h+n+1);
    deal2();
    for(int i = 1; i <= n; i++){
        // cout << Ldp[i] << " ";
    }
    // cout << endl;
    reverse(Rdp+1,Rdp+n+1);
    for(int i = 1; i <= n; i++){
        // cout << Rdp[i] << " ";
    }
    // cout << endl;
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        maxn = max(maxn,Ldp[i]+Rdp[i]);
    }
    cout << n-maxn-1;
}