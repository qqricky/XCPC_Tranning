#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int c[N];
vector<pair<int,int> >mp[N];
ll f[N]={};
int n,m;
ll ans=1e16;
void dfs(int now,ll dis){
    if(now>ans)return;
    if(f[now]<dis)return;
    f[now]=dis;
    if(now==n){
        ans=min(ans,dis);
        return;
    }
    for(auto pr:mp[now]){
        dfs(pr.first,dis+pr.second+c[pr.first]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        f[i]=1e17;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back(make_pair(v,w));
        mp[v].push_back(make_pair(u,w));
    }
    f[1]=0;
    dfs(1,0);
    cout<<ans-c[n];
    // cout.flush();
    // system("pause");
    return 0;
}