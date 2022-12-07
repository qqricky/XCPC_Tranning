#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define ull unsigned long long
#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
const int maxn=10010;
bool flag=1;
int n,m;
struct node{int v,nxt;}E[maxn<<1];
int tot,head[maxn];
int maxp[maxn],sz[maxn];
bool vis[maxn];
int sum,rt,nrt;
ull base=133331;
const ull seed=127;
int val1,val2;
ull f[N];
unordered_map<int,int>l,r;
int ansx[maxn],ansy[maxn];
ull prime[N];
bool check[N]={};
void init(){
    ll t;
    check[1]=1;
    for(int i=2;i<=80000;i++){
        if(!check[i]){
            prime[++prime[0]]=i;
        }
        for(int j=1;j<=prime[0];j++){
            t=i*prime[j];
            if(t>80000)break;
            check[t]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void add(int u,int v)
{
    E[++tot].nxt=head[u];
    E[tot].v=v;
    head[u]=tot;
}
void getrt(int u,int pa)
{
    sz[u]=1; maxp[u]=0;
    for(int i=head[u];i;i=E[i].nxt) 
    {
        int v=E[i].v;
        if(v==pa||vis[v]) continue;
        getrt(v,u);
        sz[u]+=sz[v];
        maxp[u]=max(maxp[u],sz[v]);
    }
    maxp[u]=max(maxp[u],sum-sz[u]);
    if(maxp[u]<maxp[rt]){
        rt=u;
        nrt=0;
    }
    else if(maxp[u]==maxp[rt]){
        nrt=u;
    }
}
void dfs(int now,int fa){
    sz[now]=1;
    f[now]=1;
    ull hash=0;
    for(int i=head[now];i;i=E[i].nxt) 
    {
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(v==fa) continue;
        dfs(v,now);
        sz[now]+=sz[v];
        f[now]+=f[v]*prime[sz[v]];
//         hash+=f[v];
    }
//     for(int i=head[now];i;i=E[i].nxt) 
//     {
//         if(i==val1||i==val2)continue;
//         int v=E[i].v;
//         if(v==fa) continue;
//         f[now]+=hash*prime[sz[v]];
//     }
}
void goup(int now,int y){
    vis[now]=1;
    // ans.push_back(make_pair(r[y]--,y));
    ansx[now]=r[y]--;
    ansy[now]=y;
    for(int i=head[now];i;i=E[i].nxt) 
    {
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        goup(v,y+1);
    }
}
void godown(int now,int y){
    vis[now]=1;
    // ans.push_back(make_pair(r[y]--,y));
    ansx[now]=r[y]--;
    ansy[now]=y;
    for(int i=head[now];i;i=E[i].nxt) 
    {
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        godown(v,y-1);
    }
}
void gooup(int now,int y){
    vis[now]=1;
    // ans.push_back(make_pair(l[y]++,y));
    ansx[now]=l[y]++;
    ansy[now]=y;
    for(int i=head[now];i;i=E[i].nxt) 
    {
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        gooup(v,y+1);
    }
}
void goodown(int now,int y){
    vis[now]=1;
    // ans.push_back(make_pair(l[y]++,y));
    ansx[now]=l[y]++;
    ansy[now]=y;
    for(int i=head[now];i;i=E[i].nxt) 
    {
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        goodown(v,y-1);
    }
}
void solveup(int now,int y){
    vis[now]=1;
    // ans.push_back(make_pair(0,y));
    ansx[now]=0;
    ansy[now]=y;
    map<pair<ull,int>,int>to;
    int cnt=0;
    for(int i=head[now];i;i=E[i].nxt){
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        if(to[make_pair(f[v],sz[v])]){
            cnt--;
            goup(to[make_pair(f[v],sz[v])],y+1);
            gooup(v,y+1);
            vis[v]=vis[to[make_pair(f[v],sz[v])]]=1;
            to[make_pair(f[v],sz[v])]=0;
        }
        else{
            cnt++;
            to[make_pair(f[v],sz[v])]=v;
        }
    }
    if(cnt>1){
        flag=0;
        return;
    }
    for(auto pr:to){
        if(pr.second==0)continue;
        solveup(pr.second,y+1);
    }
}
void solvedown(int now,int y){
    vis[now]=1;
    // ans.push_back(make_pair(0,y));
    ansx[now]=0;
    ansy[now]=y;
    map<pair<ull,int>,int>to;
    int cnt=0;
    for(int i=head[now];i;i=E[i].nxt){
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        if(to[make_pair(f[v],sz[v])]){
            cnt--;
            godown(to[make_pair(f[v],sz[v])],y-1);
            goodown(v,y-1);
            vis[v]=vis[to[make_pair(f[v],sz[v])]]=1;
            to[make_pair(f[v],sz[v])]=0;
        }
        else{
            cnt++;
            to[make_pair(f[v],sz[v])]=v;
        }
    }
    if(cnt>1){
        flag=0;
        return;
    }
    for(auto pr:to){
        if(pr.second==0)continue;
        solvedown(pr.second,y-1);
    }
}
void solve(int now,int y){
    map<pair<ull,int>,int>to;
    int cnt=0;
    for(int i=head[now];i;i=E[i].nxt){
        if(i==val1||i==val2)continue;
        int v=E[i].v;
        if(vis[v]) continue;
        if(to[make_pair(f[v],sz[v])]){
            cnt--;
            godown(to[make_pair(f[v],sz[v])],y-1);
            goodown(v,y-1);
            vis[v]=vis[to[make_pair(f[v],sz[v])]]=1;
            to[make_pair(f[v],sz[v])]=0;
        }
        else{
            cnt++;
            to[make_pair(f[v],sz[v])]=v;
        }
    }
    if(cnt>2){
        flag=0;
        return;
    }
    int is=0;
    for(auto pr:to){
        if(pr.second==0)continue;
        if(is){
            solveup(pr.second,y+1);
        }else{
            solvedown(pr.second,y-1);
        }
        is^=1;
    }
}
int s1[N],s2[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("8.in","r",stdin);
    freopen("1tmp.out","w",stdout);
    init();
    int t;
    cout;
    cin>>t;
    while(t--){
        E[0].nxt=0;
        cin>>n;
        flag=1;
        rt=nrt=0;
        val1=0;val2=0;
        maxp[rt]=sum=n;
        memset(head,0,sizeof(int)*(2*n));
        memset(vis,0,sizeof(bool)*(2*n+5));
        memset(f,0,sizeof(ull)*(2*n+3));
        l.clear();r.clear();
        for(int i=-n;i<=n;i++){
            r[i]=n;
            l[i]=-n;
        }
        tot=0;
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            s1[i]=u;
            s2[i]=v;
            add(u,v);add(v,u);
        }
        getrt(1,0);
        if(nrt)swap(rt,nrt);
        dfs(rt,0);
        vis[rt]=1;
        ansx[rt]=0,ansy[rt]=0;
        solve(rt,0);
        if(!flag){
            if(nrt){
                flag=1;
                swap(rt,nrt);
                memset(head,0,sizeof(int)*(2*n+3));
                memset(vis,0,sizeof(bool)*(2*n+5));
                memset(f,0,sizeof(ull)*(2*n+3));
                l.clear();r.clear();
                for(int i=-n;i<=n;i++){
                    r[i]=n;
                    l[i]=-n;
                }
                for(int i=-n;i<=n;i++){
                    r[i]=n;
                    l[i]=-n;
                }
                tot=0;
                for(int i=1;i<n;++i)
                {
                    int u,v;
                    u=s1[i];
                    v=s2[i];
                    add(u,v);add(v,u);
                }
                dfs(rt,0);
                vis[rt]=1;
                solve(rt,0);
                ansx[rt]=0,ansy[rt]=0;
                if(flag)goto ed;



                flag=1;
                memset(head,0,sizeof(int)*(2*n+3));
                memset(vis,0,sizeof(bool)*(2*n+5));
                memset(f,0,sizeof(ull)*(2*n+3));
                l.clear();r.clear();
                for(int i=-n;i<=n;i++){
                    r[i]=n;
                    l[i]=-n;
                }
                tot=0;
                for(int i=1;i<n;++i)
                {
                    int u,v;
                    u=s1[i];
                    v=s2[i];
                    if(u==rt&&v==nrt)continue;
                    if(u==nrt&&v==rt)continue;
                    add(u,v);add(v,u);
                }
                int rtt=n+1;
                add(rtt,nrt);
                add(nrt,rtt);
                add(rt,rtt);
                add(rtt,rt);
                dfs(rtt,0);
                vis[rtt]=1;
                if(f[rt]!=f[nrt]||sz[rt]!=sz[nrt]){
                    flag=0;
                    goto ed;
                }
                solve(rtt,0);
                // flag=1;
                // int rtt=n+1;
                // add(rtt,nrt);
                // add(rtt,rt);
                // memset(vis,0,sizeof(bool)*(n+5));
                // memset(f,0,sizeof(ull)*(n+3));
                // for(int i=-n;i<=n;i++){
                //     r[i]=n;
                //     l[i]=-n;
                // }
                // for(int i=head[rt];i;i=E[i].nxt){
                //     int v=E[i].v;
                //     if(v==nrt){
                //         val1=i;
                //         break;
                //     }
                // }
                // for(int i=head[nrt];i;i=E[i].nxt){
                //     int v=E[i].v;
                //     if(v==rt){
                //         val2=i;
                //         break;
                //     }
                // }
                // vis[rtt]=1;
                // dfs(rtt,0);
                // if(f[rt]!=f[nrt]||sz[rt]!=sz[nrt]){
                //     flag=0;
                //     goto ed;
                // }
                // solve(rtt,0);
            }
        }
        ed:;
        if(flag){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                cout<<ansx[i]<<' '<<ansy[i]<<'\n';
            }
            cout<<"1 0 0\n";
        }else{
            cout<<"NO\n";
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
} 