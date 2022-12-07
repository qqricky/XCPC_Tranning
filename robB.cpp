#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
vector<int>mp[N];
int p[N];
bool vis[N]={};
int ans[N]={};
int f[N]={};
int step[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,id;
    int s,t;
    cin>>n>>m>>k>>id;
    id--;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if(x==y)continue;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    cin>>s>>t;
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(q.size()){
        int now=q.front();
        q.pop();
        for(int x:mp[now]){
            if(vis[x])continue;
            step[x]=step[now]+1;
            vis[x]=1;
            q.push(x);
        }
    }
    memset(vis,0,sizeof(vis));
    q.push(t);
    vis[t]=1;
    if(step[t]%k==id)f[t]=p[t];
    while(q.size()){
        int now=q.front();
        q.pop();
        int sp=step[now];
        for(int x:mp[now]){
            if(step[x]!=step[now]-1)continue;
            int ssp=step[x];
            if(ssp%k==id){
                f[x]=max(f[x],f[now]+p[x]);
            }else{
                f[x]=max(f[x],f[now]);
            }
            if(vis[x])continue;
            vis[x]=1;
            q.push(x);
        }
    }
    cout<<f[s];
    // cout.flush();
    // system("pause");
    return 0;
}