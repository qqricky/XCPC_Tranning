#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
vector<int>mp[N];
int ans=0;
int anss=0;
int son[N]={};
int f[N]={};
int ff[N]={};
int h[N]={};
int g[N]={};
int p1,p2;
int p;
void dfs(int now,int fa){
    for(int x:mp[now]){
        if(x==fa){
            continue;
        }
        dfs(x,now);
    }
    int m=0;
    int to=0;
    int sm=0;
    int sto=0;
    for(int x:mp[now]){
        if(x==fa)continue;
        if(f[x]>m){
            sto=to;
            sm=m;
            m=f[x];
            to=x;
        }else if(f[x]>sm){
            sm=f[x];
            sto=x;
        }
        if(sm+m+a[now]>ans){
            ans=sm+m+a[now];
            p=now;
            p1=to;
            p2=sto;
        }
    }
    if(m==0){
        if(a[now]>ans){
            ans=a[now];
            p=now;
            p1=0,p2=0;
        }
    }
    f[now]=m+a[now];
    if(sto!=0)
    ff[now]=sm+a[now];
    son[now]=to;
}
void calc(int now,int fa){
    for(int x:mp[now]){
        if(x==fa)continue;
        if(f[x]==f[now]-a[now]){
            g[x]=ff[now]+a[x];
        }else{
            g[x]=f[now]+a[x];
        }
        g[x]=max(g[x],g[now]+a[x]);
        calc(x,now);
    }
}
void calch(int now,int fa){
    for(int x:mp[now]){
        if(x==fa)continue;
        calch(x,now);
        h[now]=max(h[now],h[x]);
    }
    if(ff[now]!=0){
        h[now]=max(h[now],f[now]+ff[now]-a[now]);
    }
    else{
        h[now]=max(h[now],f[now]+ff[now]);
    }
}
void solve(int now,int fa){
    multiset<int>s;
    for(int x:mp[now]){
        if(x==fa)continue;
        solve(x,now);
        s.insert(f[x]+a[now]);
    }
    s.insert(g[now]);
    s.insert(a[now]);
    s.insert(a[now]);
    s.insert(a[now]);
    int mx=0;
    int mx2=0;
    for(int x:mp[now]){
        if(x==fa)continue;
        s.erase(s.find(f[x]+a[now]));
        if(h[x]>mx){
            mx2=mx;
            mx=h[x];
        }else if(h[x]>mx2){
            mx2=h[x];
        }
        auto it=s.end();
        it--;
        int tmp=*it;
        it--;
        tmp+=*it;
        s.insert(f[x]+a[now]);
        anss=max(anss,tmp+h[x]-a[now]);
    }
    s.insert(a[now]);
    s.insert(a[now]);
    // anss=max(anss,tmp);
    anss=max(anss,mx+mx2);
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int res=0;
    dfs(1,0);
    g[1]=a[1];
    calc(1,0);
    calch(1,0);
    solve(1,0);
    // cout<<"sdaklfjl "<<p<<endl;
    res+=ans;
    a[p]*=-1;
    while(p1){
        a[p1]*=-1;
        p1=son[p1];
    }
    while(p2){
        a[p2]*=-1;
        p2=son[p2];
    }
    memset(f,0,sizeof(f));
    memset(son,0,sizeof(son));
    p=0;
    ans=0;
    dfs(1,0);
    if(ans>0)res+=ans;
    if(n==1)res=0,anss=0;
    cout<<max(res,anss);
    cout.flush();
}
