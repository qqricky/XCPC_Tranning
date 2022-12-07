#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MST(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const ll mod=1e4;
const int L=26,maxn=100050;
int n,m,k,T;
struct Edge {
	int to,next,cap,flow;//cap：盖子就是在建图的时候如果需要建立回路那么就传入addege(u,v,w,w);,这样比传两遍快。
} edge[maxn*4];
int tol,head[maxn],gap[maxn],dep[maxn],S[maxn],cur[maxn];
void init() { //初始化
	tol=0,MST(head,-1);
}
void addedge(int u,int v,int w,int rw=0) { //建图
	edge[tol].to=v;
	edge[tol].cap=w;
	edge[tol].next=head[u];
	edge[tol].flow=0;
	head[u]=tol++;
	edge[tol].to=u;
	edge[tol].cap=rw;
	edge[tol].next=head[v];
	edge[tol].flow=0;
	head[v]=tol++;
}
int Q[maxn];
void bfs(int st,int en) {
	MST(dep,-1),MST(gap,0);
	memset(gap,0,sizeof(gap));
	gap[0]=1;
	int front=0,rear=0;
	dep[en]=0,Q[rear++]=en;
	while(front!=rear) {
		int u=Q[front++];
		for(int i=head[u]; i!=-1; i=edge[i].next) {
			int v=edge[i].to;
			if(dep[v]!=-1) continue;
			Q[rear++]=v;
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}
}
ll sap(int st,int en,int N) {
	bfs(st,en);
	memcpy(cur,head,sizeof(head));
	int top=0,u=st;
    ll ans=0;
	while(dep[st]<N) {
		if(u==en) {
			ll Min=INF,inser;
			for(int i=0; i<top; i++)
				if(Min>edge[S[i]].cap-edge[S[i]].flow)
					Min=edge[S[i]].cap-edge[S[i]].flow,inser=i;
			for(int i=0; i<top; i++)
				edge[S[i]].flow+=Min,edge[S[i]^1].flow-=Min;
			ans+=Min,top=inser,u=edge[S[top]^1].to;
			continue;
		}
		bool flag=false;
		int v;
		for(int i=cur[u]; i!=-1; i=edge[i].next) {
			v=edge[i].to;
			if(edge[i].cap-edge[i].flow&&dep[v]+1==dep[u]) {
				flag=true,cur[u]=i;
				break;
			}
		}
		if(flag) {
			S[top++]=cur[u];
			u=v;
			continue;
		}
		ll Min=N;
		for(int i=head[u]; i!=-1; i=edge[i].next)
			if(edge[i].cap-edge[i].flow&&dep[edge[i].to]<Min)
				Min=dep[edge[i].to],cur[u]=i;
		gap[dep[u]]--;
		if(!gap[dep[u]]) return ans;
		dep[u]=Min+1,gap[dep[u]]++;
		if(u!=st) u=edge[S[--top]^1].to;
	}
	return ans;
}
int main() {
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
	int start,End;
	int m;
	int u,v,z;
	int T=1;
	while(T--) {
		init();
		scanf("%d %d %d %d",&n,&m,&start,&End);
		while(m--) {
			scanf("%d%d%d",&u,&v,&z);
			addedge(u,v,z);
		}
		ll ans=sap(start,End,n);
		printf("%d\n",ans);
	}
    //system("pause");
	return 0;
}