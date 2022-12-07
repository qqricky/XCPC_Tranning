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
ll val[N];
bool vis[N];
deque<int>q;
void dfs(int ver,ll tans)
{
    //cout<<ver<<"www "<<tans<<endl;
    //cout<<ver<<" qqqqq"<<endl;
    //cout<<mp[ver].size()<<endl;
    if(mp[ver].size()==1){
        ans=max(ans,tans);
        return ;
    }
    int now;
    for(int j=0;j<mp[ver].size();j++){
        if(vis[eg[mp[ver][j]].y]){
            now=eg[mp[ver][j]].y;
            break;
        }
    }
    for(int j=0;j<mp[ver].size();j++){
        int k=mp[ver][j];
        if(eg[k].y==now)continue;
        if(2*val[ver]*eg[k].w<=p){
            val[eg[k].y]=val[ver]+eg[k].w;
            tans=tans+eg[k].w*eg[k].w+2*val[ver]*eg[k].w;
        }
        else{
            val[eg[k].y]=eg[k].w;
            tans=tans+eg[k].w*eg[k].w+p;
        }
        vis[eg[k].y]=1;
        dfs(eg[k].y,tans);
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
        cin>>n>>p;
        tot=0;
        memset(val,0,sizeof(ll)*(n+1));
        memset(vis,0,sizeof(bool)*(n+1));
        for(int i=1;i<=n;i++)mp[i].clear();
        vis[1]=1;
        for(int i=1;i<n;i++){
            tot++;
            cin>>eg[tot].x>>eg[tot].y>>eg[tot].w;
            mp[eg[tot].x].push_back(tot);
            tot++;
            eg[tot].y=eg[tot-1].x;
            eg[tot].x=eg[tot-1].y;
            eg[tot].w=eg[tot-1].w;
            mp[eg[tot].x].push_back(tot);
        }
        for(int j=0;j<mp[1].size();j++){
            int kk=mp[1][j];
            val[eg[kk].y]=eg[kk].w;
            vis[eg[kk].y]=1;
            dfs(eg[kk].y,eg[kk].w*eg[kk].w);
        }
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}