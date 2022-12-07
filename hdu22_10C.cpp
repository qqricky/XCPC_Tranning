#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int f[N];
vector<int>mp[N];
int du[N];
int val[N];
const int maxn=10010;
const int maxm=40010;
struct edge{
	int to,next;
    int st;
	int cap,flow;
}edge[maxm];
int tol;
int head[maxn];
bool vis[maxn]={};
int gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init(){
	tol=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0){
    edge[tol].st=u;
	edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
	edge[tol].flow=0;head[u]=tol++;
    edge[tol].st=v;
	edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
	edge[tol].flow=0;head[v]=tol++;
}
int sap(int st,int ed,int nn){
	memset(gap,0,sizeof(gap));
	memset(dep,0,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	int u=st;
	pre[u]=-1;
	gap[0]=nn;
	int ans=0;
	while(dep[st]<nn){
		if(u==ed){
			int Min=INF;
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
		int Min=nn;
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
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m1,m2;
        cin>>n>>m2>>m1;
        memset(f,0,sizeof(int)*(n+4));
        memset(vis,0,sizeof(bool)*(n+4));
        for(int i=1;i<=m2;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(z)f[x]++;
            else f[y]++;
        }
        init();
        int st=1;
        int ed=2;
        int cnt=0;
        for(int i=1;i<=m1;i++){
            int x,y;
            cin>>x>>y;
            if(x==1||y==1){
                f[1]++;
                continue;
            }
            cnt++;
            addedge(st,i+2,1);
            addedge(i+2,x+2+m1,1);
            addedge(i+2,y+2+m1,1);
        }
        bool flag=1;
        int mx=f[1];
        for(int i=2;i<=n;i++){
            if(f[i]>mx){
                flag=0;
                break;
            }
            addedge(i+2+m1,ed,mx-f[i]);
        }
        int maxflow=sap(st,ed,m1+2+n);
        if(maxflow!=cnt)flag=0;
        if(flag)std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
    // std::cout.flush();
    // std::system("pause");
    return 0;
}