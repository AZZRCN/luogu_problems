#include <bits/stdc++.h>
using namespace std;
int n,ans,quan[100005];
int a[100005],b[100005];
int q[100005],p[100005],c[100005];
void msort(int l,int r){
    if(l==r)  
	return;
    int mid=(l+r)/2,i=l,j=mid+1,k=l;
    msort(l,mid),msort(mid+1,r);
    while(i<=mid&&j<=r)
    if(q[i]<=q[j])
    c[k++]=q[i++];
    else
    c[k++]=q[j++],ans+=mid-i+1;
    while(i<=mid)
    c[k++]=q[i++];
    while(j<=r)
    c[k++]=q[j++];
    for(int l=l;l<=r;l++)
    q[l]=c[l];
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++) q[i]=a[i];
	for(int i=1;i<=n;i++) p[i]=b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int cnt=unique(a+1,a+n+1)-(a+1);
	int num=unique(b+1,b+n+1)-(b+1);
	for(int i=1;i<=n;i++)
    q[i]=lower_bound(a+1,a+cnt+1,q[i])-a;
    for(int i=1;i<=n;i++)
    p[i]=lower_bound(b+1,b+num+1,p[i])-b;
	for(int i=1;i<=n;i++)
	quan[p[i]]=i;
	for(int i=1;i<=n;i++)
	q[i]=quan[q[i]];
	msort(1,n);
	cout<<ans%99999997;
	return 0;
}