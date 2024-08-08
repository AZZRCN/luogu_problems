//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
inline void maxn(int &a,int b){a = max(a,b);}
inline void minn(int &a,int b){a = min(a,b);}
const int N = 2e5+10;
int n;
struct{
	int to,from,nex,w;
	#define to(x) g[x].to
	#define from(x) g[x].from
	#define nex(x) g[x].nex
	#define w(x) g[x].w
}g[N<<1];
int head[N<<1],edge_num;
inline void add(int a,int b,int w){
	to(++edge_num) = b;
	from(edge_num) = a;
	nex(edge_num) = head[a];
	head[a] = edge_num;
	w(edge_num) = w;
}
ll dis[N],maxd;
int fa[N],pos;
inline void dfs_lr(int now,int fu){
	fa[now] = fu;
	if(dis[now]>maxd){
		maxd = dis[now];
		pos = now;
	}
	for(int i=head[now];i;i=nex(i)){
		int tto = to(i);
		if(tto==fu) continue;
		dis[tto] = dis[now]+w(i);
		dfs_lr(tto,now);
	}
}
int vis_zj[N];//直径上的点 
inline void dfs_mxd(int now,int fu){
	if(dis[now]>maxd){
		maxd = dis[now];
	}
	for(int i=head[now];i;i=nex(i)){
		int tto = to(i);
		if(vis_zj[tto]||tto==fu) continue;
		dis[tto] = dis[now]+w(i);
		dfs_mxd(tto,now); 
	}
}
int lef,righ;
inline void work_zjdis(){
	maxd = 0;
	dfs_lr(1,0);
	lef = pos;
	maxd = 0;
	dis[lef] = 0;
	dfs_lr(lef,0);
	righ = pos;
	printf("%lld\n",maxd);
}
inline void work_zjnum(){
	int l = lef,r = righ;
	for(int i=r;i;i=fa[i]) vis_zj[i]=1;
	int flag = 1;
	for(int i=fa[r];i!=l;i=fa[i]){
		ll ld = dis[i],rd = dis[r]-dis[i];//点到直径两端距离 
		dis[i] = 0;//直径上点的子树分别求最长距离 
		maxd = 0;
		dfs_mxd(i,0); 
		//l和r分别找到子树的最左端和最右端
		//所以左或者右只用找一次 
		if(maxd==rd) righ=i;
		if(maxd==ld && flag) lef=i,flag = 0;
	}
	int ans = 1;//ans初始化1因为下面没有算i==lef的情况 
	for(int i=fa[righ];i!=lef;i=fa[i]) ans++;
	printf("%d",ans);
}
int main(){
	read(n);
	for(int i=1,u,v,w;i<n;++i){
		read(u,v,w);
		add(u,v,w);add(v,u,w);
	}
	work_zjdis();
	work_zjnum();
//	for(int i=1;i<=n;++i) cout << fa[i] << endl;
	return 0;
}