#include <bits/stdc++.h>
#define ll long long
//#pragma GCC optimise(2)
using namespace std;
const int maxn=100100;
const int maxm=300100;
const int INF=0x3f3f3f3f;
struct edge{
    int now;
	int to,next;
	int cap,flow;
}edge[maxm];
int tol;
int head[maxn];
vector<int>ansv[maxn];
int gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init(){
	tol=2;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0){
    edge[tol].now=u;
	edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
	edge[tol].flow=0;head[u]=tol++;
    edge[tol].now=v;
	edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
	edge[tol].flow=0;head[v]=tol++;
}
int Q[maxn];
int sta[maxn];
bool bfs(int s,int t,int n){
	int front =0,tail =0;
	memset(dep,-1,sizeof(dep[0])*(n+2));
	dep[s]=0;
	Q[tail++]=s;
	while(front<tail){
		int u=Q[front++];
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>edge[i].flow&&dep[v]==-1){
				dep[v]=dep[u]+1;
				if(v==t)return true;
				Q[tail++]=v;
			}
		}
	}
	return false;
}
int dinic(int s,int t,int n){
	int maxflow=0;
	while(bfs(s,t,n)){
		for(int i=0;i<=n;i++)cur[i]=head[i];
		int u=s,tail=0;
		while(cur[s]!=-1){
			if(u==t){
				int tp=INF;
				for(int i=tail-1;i>=0;i--)
					tp=min(tp,edge[sta[i]].cap-edge[sta[i]].flow);
				maxflow+=tp;
				for(int i=tail-1;i>=0;i--){
					edge[sta[i]].flow+=tp;
					edge[sta[i]^1].flow-=tp;
					if(edge[sta[i]].cap-edge[sta[i]].flow==0)
						tail=i;
				}
				u=edge[sta[tail]^1].to;
			}
			else if(cur[u]!=-1&&edge[cur[u]].cap>edge[cur[u]].flow&&dep[u]+1==dep[edge[cur[u]].to]){
				sta[tail++]=cur[u];
				u=edge[cur[u]].to;
			}
			else{
				while(u!=s&&cur[u]==-1)
					u=edge[sta[--tail]^1].to;
				cur[u]=edge[cur[u]].next;
			}
		}
	}
	return maxflow;
}
int a[110][110];
int n,m;
inline bool ck(int x,int y){
    if(x<1||x>m||y<1||y>n){
        return 0;
    }
    return 1;
}
inline int calc(int x,int y){
    return (x-1)*n+y;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>m>>n;
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            ans+=a[i][j];
        }
    }
    int s=0,t=n*m+1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int val=calc(i,j);
            if((i+j)&1){
                addedge(val,t,a[i][j]);
            }
            else{
                addedge(s,val,a[i][j]);
                if(ck(i-1,j)){
                    addedge(val,calc(i-1,j),INF);
                }
                if(ck(i,j-1)){
                    addedge(val,calc(i,j-1),INF);
                }
                if(ck(i+1,j)){
                    addedge(val,calc(i+1,j),INF);
                }
                if(ck(i,j+1)){
                    addedge(val,calc(i,j+1),INF);
                }
            }
        }
    }
    int maxflow=dinic(s,t,n*m+1);
    ans-=maxflow;
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}