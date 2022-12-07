#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll ans=0;
ll n,p;
vector<int>mp[N];
struct edge
{
    int x,y;
    ll w;
}eg[2*N];
int f[N][2];
int l[N];
int r[N];
void dfs(int u,int fa)
{
    for(int i=0;i<mp[u].size();i++){
        
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int tot;
    while(t--)
    {
        cin>>n;
        memset(f,-1,sizeof(f));
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
        for(int i=1;i<=n;i++){
            tot++;
            cin>>eg[tot].x>>eg[tot].y>>eg[tot].w;
            mp[eg[tot].x].push_back(tot);
            tot++;
            eg[tot].y=eg[tot-1].x;
            eg[tot].x=eg[tot-1].y;
            eg[tot].w=eg[tot-1].w;
            mp[eg[tot].x].push_back(tot);
        }
        cout<<max(f[1][0],f[1][1])<<"\n";
        cout.flush();
    }
    system("pause");
    return 0;
}