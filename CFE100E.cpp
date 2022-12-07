#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N=3e5+10;
int f[N]={};
int a[N]={};
int zuo[N]={};
int you[N]={};
int ind[N]={};
int ans[N]={};
int v[N]={};
vector<int>Fr[N];
vector<int>G[N];
int Find(int x)
{
    return f[x]==x ? x : f[x]=Find(f[x]);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int root;
    for(int i=1;i<=n;i++){
        f[i]=i;
        int z;
        cin>>z;
        if(z)Fr[z].push_back(i);
        else root=i;
    }
    int x,y;
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        if(you[x]||zuo[y]){cout<<0;return 0;}
        you[x]=y;
        zuo[y]=x;
        x=Find(x);
        if(x==y){cout<<0;return 0;}
        f[y]=x;
    }
    for(int i=1;i<=n;i++){
        for(auto m : Fr[i]){
            if(Find(i)!=Find(m)){
                G[Find(i)].push_back(Find(m));
                ind[Find(m)]++;
            }
        }
    }
    queue<int>q;
    q.push(root);
    int cnt=0;
    while(q.size())
    {
        int u=q.front();
        int tmp=u;
        q.pop();
        while(u)
        {
            ans[++cnt]=u;
            u=you[u];
        }
        for(auto m : G[tmp]){
            ind[m]--;
            if(!ind[m])q.push(m);
        }
    }
    if(cnt!=n){cout<<0;return 0;}
    v[root]=1;
    for(int i=1;i<=n;i++){
        if(v[ans[i]]==0){cout<<0;return 0;}
        else for(auto m : Fr[ans[i]])v[m]=1;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    system("pause");
    return 0;
}