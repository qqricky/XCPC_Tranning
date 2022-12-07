#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
bool v[N]={};
struct qnode
{
    ll v,c;
    qnode(ll _v=0,ll _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const{
        return c>r.c;
    }
};
struct Edge
{
    ll v,cost;
    Edge(ll _v=0,ll _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[N];
bool vis[N];
ll dist[N];
void dijkstra(int n,int start){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty()){
        tmp=que.top();
        que.pop();
        ll u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++){
            ll v=E[tmp.v][i].v;
            ll cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost){
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(ll u,ll v,ll w){
    E[u].push_back(Edge(v,w));
    E[v].push_back(Edge(u,w));
}
vector<int>mp[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    r=((r+1)/2);
    int cnt=0;
    for(int i=1;i<=m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        cnt++;
        x++,y++;
        mp[x].push_back(cnt);
        mp[y].push_back(cnt);
        addedge(x,y,l);
    }
    dijkstra(n,1);
    for(int i=1;i<=n;i++){
        if(dist[i]<r){
            for(int u:mp[i]){
                v[u]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(v[i])ans++;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}