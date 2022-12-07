#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
bool vis[N]={};
int fa[N]={};
ll dep[N];
vector<int>mp[N];
void dfs(int now,int val){
    dep[now]=val;
    for(int x:mp[now]){
        dfs(x,val+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    vis[1]=1;
    for(int i=1;i<=n;i++){
        cin>>fa[i];
        if(fa[i]!=-1){
            mp[fa[i]].push_back(i);
        }
    }
    dfs(1,0);
    ll ans=0;
    ll ma=0;
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        ma=max(ma,dep[x]);
        ll tmp=0;
        while(!vis[x]){
            vis[x]=1;
            tmp++;
            x=fa[x];
        }
        ans+=tmp*2;
        cout<<ans-ma;
        if(i!=q)cout<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}