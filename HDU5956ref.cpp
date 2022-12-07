#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N=1e5+100;
int n;
ll a[N],sum[N],d[N],k;
int q[N],hd,tl;
int head[N],to[N<<1],nxt[N<<1],nEdge;
ll cost[N<<1],ans;
 
void AddEdge(int u,int v,ll c)
{
    nxt[nEdge]=head[u],to[nEdge]=v,cost[nEdge]=c,head[u]=nEdge++;
}
 
ll dy(int a,int b)
{
    return d[a]+sum[a]*sum[a]-d[b]-sum[b]*sum[b];
}
 
ll dx(int a,int b)
{
    return 2*(sum[a]-sum[b]);
}
 
void dfs(int u,int i,int fa)
{
    int oldhd=hd,oldtl=tl;
    while(hd<tl&&dy(q[hd+1],q[hd])<=dx(q[hd+1],q[hd])*sum[i])hd++;
    d[i]=d[q[hd]]+(sum[i]-sum[q[hd]])*(sum[i]-sum[q[hd]])+k;
    ans=max(ans,d[i]);
    while(hd<tl&&dy(i,q[tl])*dx(q[tl],q[tl-1])<=dx(i,q[tl])*dy(q[tl],q[tl-1]))tl--;
    int x=q[++tl];
    q[tl]=i;
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(v==fa)continue;
        sum[i+1]=sum[i]+cost[e];
        dfs(v,i+1,u);
    }
    q[tl]=x;
    hd=oldhd,tl=oldtl;
}
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof head);
        nEdge=0;
        scanf("%d%lld",&n,&k);
        for(int i=1; i<n; ++i)
        {
            int u,v;
            ll c;
            scanf("%d%d%lld",&u,&v,&c);
            AddEdge(u,v,c);
            AddEdge(v,u,c);
        }
        hd=0,tl=-1;
        q[++tl]=0;
        d[0]=0;
        ans=0;
        dfs(1,1,0);
        printf("%lld\n",ans-k);
    }
    return 0;
}