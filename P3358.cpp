#include <bits/stdc++.h>
#define ll long long
#define INF 1e16
//#pragma GCC optimise(2)
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=1e4+10;
const int maxm=1e5+10;
struct edge{
    ll to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
ll dis[maxn];
bool vis[maxn];
int N;
void init(int n){
    N=n;;
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,ll cap,int cost){
    cost=-cost;
    edge[tol].to=v;
    edge[tol].cap=cap;
    edge[tol].cost=cost;
    edge[tol].flow=0;
    edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].cost=-cost;
    edge[tol].flow=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}
bool spfa(int s,int t){
    queue<int>q;
    for(int i=0;i<N;i++){
        dis[i]=INF;
        vis[i]=0;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow && dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1)return false;
    else return true;
}
int minCostMaxflow(int s,int t,ll &cost){
    ll flow=0;
    cost=0;
    while(spfa(s,t)){
        ll Min=INF;
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            if(Min>edge[i].cap-edge[i].flow)
                Min=edge[i].cap-edge[i].flow;
        }
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }
        flow+=Min;
    }
    return flow;
}
int n,k;
int l[505],r[505];
int go[1070];
map<int,int>mp;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    init(2*n+2);
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        go[i*2-1]=l[i];
        go[i*2]=r[i];
    }
    sort(go+1,go+n*2+1);
    int ed=unique(go+1,go+n*2+1)-go-1;
    for(int i=1;i<=ed;i++){
        mp[go[i]]=i;
    }
    int s=0,t=ed+1;
    for(int i=1;i<=ed+1;i++){
        addedge(i-1,i,k,0);
    }
    for(int i=1;i<=n;i++){
        addedge(mp[l[i]],mp[r[i]],1,r[i]-l[i]);
    }
    ll ans=0;
    minCostMaxflow(s,t,ans);
    cout<<-ans;
    cout.flush();
    //system("pause");
    return 0;
}