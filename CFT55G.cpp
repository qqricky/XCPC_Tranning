#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll f[N]={};
ll sz[N]={};
ll g[N]={};
vector<int>mp[N];
int n;
int rt;
void dfs1(int now,int fa){
    sz[now]=1;
    for(int v:mp[now]){
        if(v==fa){
            continue;
        }
        dfs1(v,now);
        sz[now]+=sz[v];
    }
}
void dfs(int now,int fa){
    ll sum=0;
    ll acu=0;
    g[now]=sz[rt];
    for(int v:mp[now]){
        if(v==fa){
            continue;
        }
        dfs(v,now);
        f[now]+=f[v];
        acu+=g[v];
        sum+=f[v];
    }
    for(int v:mp[now]){
        if(v==fa)continue;
        // if(now==2){
        //     cout<<v<<' '<<g[v]<<endl;
        // }
        g[now]=max(g[now],g[v]+(1)*(sz[rt]-sz[v])+sum-f[v]);

    }
    f[now]+=sz[now];
}
int deg[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    rt=1;
    for(int i=1;i<=n;i++){
        if(deg[i]>1){
            rt=i;
            break;
        }
    }
    dfs1(rt,0);
    dfs(rt,0);
    for(int i=1;i<=n;i++){
        // cout<<i<<' '<<g[i]<<endl;
    }
    cout<<g[rt];
    cout.flush();
    // system("pause");
    return 0;
}