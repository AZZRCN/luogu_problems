#include<bits/stdc++.h>
using namespace std;
#define N 22
int n, a[1000005], f[1<<N];
int main() {
    freopen("in","r",stdin);
	cin>>n;
    memset(f, -1 , sizeof(f));
	for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        f[a[i]]=a[i];
	}
    for(int i = 0; i < N; i++){//前i位
        for(int j = 0; j < (1<<N); j++){
            f[i][j] = f[i-1][j];//上一维
            if(j&(1<<i)){
                f[i][j]=max(f[i][j] , f[i][j^(1<<(i))]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int b = ((1<<N)-1)^a[i];
        cout << f[N-1][b] << endl;
    }
}