#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<pair<int,int> >mp[N];
ll ans=0;
int sz[N];
int pre[N];
int last[N];
ll g[2*N];
void getsize(int now,int fa){
    sz[now]=1;
    for(auto pr:mp[now]){
        if(pr.first==fa)continue;
        getsize(pr.first,now);
        sz[now]+=sz[pr.first];
    }
}
void dfs(int now,int fa,int tp){
    g[now]=sz[now];
    pre[now]=last[tp];
    g[pre[now]]-=sz[now];
    last[tp]=now;
    for(auto pr:mp[now]){
        int v=pr.first;
        if(v==fa)continue;
        dfs(v,now,pr.second);
    }
    last[tp]=pre[now];
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        mp[x].push_back(make_pair(y,z));
        mp[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=n;i++){
        last[i]=i+n;
        g[i+n]=n;
    }
    getsize(1,0);
    dfs(1,0,0);
    for(int i=2;i<=n;i++){
        ans+=g[i]*g[pre[i]];
    }
    cout<<ans;
    cout.flush();
    // system("pause");
    return 0;
}