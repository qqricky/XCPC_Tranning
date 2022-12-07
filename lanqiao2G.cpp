#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int deg[N];
vector<int>mp[N];
int f[N][18];
int sum[N];
void dfs(int now,int fa){
    sum[now]=sum[fa]+deg[now];
    f[now][0]=fa;
    for(int x:mp[now]){
        if(x==fa)continue;
        dfs(x,now);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    dfs(1,1);
    for(int j=1;j<=17;j++){
        for(int i=1;i<=n;i++){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(u==v){
            cout<<deg[u]<<'\n';
            continue;
        }
        int x=u,y=v;
        for(int j=17;j>=0;j--){
            if(f[x][j]!=f[y][j]){
                x=f[x][j];
                y=f[y][j];
            }
        }
        int fa=f[x][0];
        cout<<sum[u]+sum[v]-2*sum[fa]+deg[fa]<<'\n';
        // cout<<sum[u]<<' '<<sum[v]<<' '<<sum[fa]<<' '<<fa<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}