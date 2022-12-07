#include <bits/stdc++.h>
#define ll long long
//#pragma GCC optimise(2)
using namespace std;
const int maxn=100010;
const int maxm=400010;
const ll INF=1e17;
struct edge{
	int to,next;
    int st;
	ll cap,flow;
}edge[maxm];
int tol;
int head[maxn];
bool vis[maxn]={};
ll gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init(){
	tol=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,ll w,ll rw=0){
    edge[tol].st=u;
	edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
	edge[tol].flow=0;head[u]=tol++;
    edge[tol].st=v;
	edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
	edge[tol].flow=0;head[v]=tol++;
}
ll sap(int st,int ed,int N){
	memset(gap,0,sizeof(gap));
	memset(dep,0,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	int u=st;
	pre[u]=-1;
	gap[0]=N;
	ll ans=0;
	while(dep[st]<N){
		if(u==ed){
			ll Min=INF;
			for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
				if(Min>edge[i].cap-edge[i].flow)
					Min=edge[i].cap-edge[i].flow;
			for(int i=pre[u];i!=-1;i=pre[edge[i^1].to]){
				edge[i].flow+=Min;
				edge[i^1].flow-=Min;	
                vis[i]^=1;
                vis[i^1]^=1;
			}
			u=st;
			ans+=Min;
			continue;
		}
		bool flag=false;
		int v;
		for(int i=cur[u];i!=-1;i=edge[i].next){
			v=edge[i].to;
			if(edge[i].cap-edge[i].flow && dep[v]+1 == dep[u]){
				flag=true;
				cur[u]=pre[v]=i;
				break;
			}
		}
		if(flag){
			u=v;
			continue;
		}
		ll Min=N;
		for(int i=head[u];i!=-1;i=edge[i].next)
			if(edge[i].cap-edge[i].flow && dep[edge[i].to]<Min){
				Min =dep[edge[i].to];
				cur[u]=i;
			}
		gap[dep[u]]--;
		if(!gap[dep[u]])return ans;
		dep[u]=Min+1;
		gap[dep[u]]++;
		if(u!=st)u=edge[pre[u]^1].to;
	}
	return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m,s,t;
    s=1,t=2;
	cin>>m>>n;
	init();
    for(int i=1;i<=m;i++){
        addedge(1,i+2,1);
    }
    for(int i=m+1;i<=n;i++){
        addedge(2+i,2,1);
    }
    int x,y;
    cin>>x>>y;
    while(x!=-1 && y!=-1){
        addedge(x+2,y+2,1);
        //cout<<x<<' '<<y<<endl;
        cin>>x>>y;
    }
	ll ans=sap(s,t,n+2);
	cout<<ans<<'\n';
    for(int i=n*2;i<tol;i++){
        if(vis[i]&&edge[i].st<edge[i].to){
            cout<<edge[i].st-2<<' '<<edge[i].to-2<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}