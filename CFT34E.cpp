#include<bits/stdc++.h>
#pragma GCC optimise(2)
#define next Next
using namespace std;
typedef long long ll;
const int MAXN = 105;
const int MAXM = 105*105+5;
const int INF = 0x3f3f3f3f;
struct Edge{
	int to,next,cap,flow;
}edge[MAXM];
int tot;
int head[MAXN];
void init(){
	tot = 2;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v,int w,int rw=0){
	//cout << u << ' ' << v << ' ' << w << endl;
	edge[tot].to = v;edge[tot].cap = w;edge[tot].flow = 0;
	edge[tot].next = head[u];head[u] = tot++;
	edge[tot].to = u;edge[tot].cap = rw;edge[tot].flow = 0;
	edge[tot].next = head[v];head[v] = tot++;
}
int Q[MAXN];
int dep[MAXN],cur[MAXN],sta[MAXN];
bool bfs(int s,int t,int n){
	int front = 0,tail = 0;
	memset(dep,-1,sizeof(dep[0])*(n+1));
	dep[s] = 0;
	Q[tail++] = s;
	while(front<tail){
		int u = Q[front++];
		for(int i = head[u];i!=-1;i=edge[i].next){
			int v = edge[i].to;
			if(edge[i].cap>edge[i].flow&&dep[v]==-1){
				dep[v]=dep[u]+1;
				if(v==t) return 1;
				Q[tail++] = v;
			}
		}
	}
	return false;
}
int dinic(int s,int t,int n){
	int maxflow = 0;
	while(bfs(s,t,n)){
		for(int i = 0;i < n;++i) cur[i] = head[i];
		int u = s,tail = 0;
		while(cur[s]!=-1){
			if(u==t){
				int tp = INF;
				for(int i = tail-1;i>=0;--i) tp = min(tp,edge[sta[i]].cap-edge[sta[i]].flow);
				maxflow += tp;
				for(int i = tail-1;i>=0;--i){
					edge[sta[i]].flow += tp;
					edge[sta[i]^1].flow -= tp;
					if(edge[sta[i]].cap-edge[sta[i]].flow==0) tail = i;
				}
				u = edge[sta[tail]^1].to;
			}else if(cur[u]!=-1&&edge[cur[u]].cap>edge[cur[u]].flow&&dep[u]+1==dep[edge[cur[u]].to]){
				sta[tail++] = cur[u];
				u = edge[cur[u]].to;
			}else{
				while(u!=s&&cur[u]==-1){
					u=edge[sta[--tail]^1].to;
				}
				cur[u] = edge[cur[u]].next;
			}
		}
	}
	return maxflow;
}
int inp[100005];
void input(int n){
	int s = 1,t = 0;
	for(int i = 1;i <= n;++i){
		char c = getchar();
		while(!(c=='*'||c<='9'&&c>='0')) c=getchar();
		if(c=='*'){
			int d;scanf("%d",&d);
			if(i==d&&i!=1) continue;
			if(d==1) addedge(i,t,INF);
			else addedge(i,d,INF);
		}else{
			int cnt =0;;
			while(c<='9'&&c>='0'){
				cnt = cnt*10+c-'0';
				c=getchar();
			}
			for(int i = 0;i < cnt;++i){
				scanf("%d",inp+i);
			}
			sort(inp,inp+cnt);
			int now = 1;
			for(int j = 1;j < cnt;++j){
				if(inp[j]==inp[j-1])++now;
				else{
					if(inp[j-1]==i&&i!=1){
						now = 1;
						continue;
					}else{
						if(inp[j-1]==1) addedge(i,t,now);
						else addedge(i,inp[j-1],now);
						now = 1;
					}
				}
			}
			if(cnt>0){
				if(inp[cnt-1]==1) addedge(i,t,now);
				else if(inp[cnt-1]!=i) addedge(i,inp[cnt-1],now);
			}
		}
	}
}
int main(){
    
	int n;
    scanf("%d",&n);
	init();
	int s = 1,t = 0;
	input(n);
	int ans = dinic(s,t,n+1);
	if(ans>=INF) printf("*\n");
	else printf("%d\n",ans+1);
	return 0;
}