#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int v[N];
vector<int>mp[N];
int du[N]={};
int f[N]={};
int ff[N]={};
void dfs1(int now,int fa){
    ff[now]=fa;
    for(int x:mp[now]){
        if(x==fa)continue;
        dfs1(x,now);
    }
}
unordered_map<int,int>cnt1;
unordered_map<int,int>cnt2;
void dfs2(int now,int fa,int lev,int acu,int g){
    cnt1[v[now]-lev]++;
    cnt2[v[now]+lev]++;
    acu=min(acu,lev-cnt1[v[now]-lev]-1);
    acu=min(acu,lev-cnt2[v[now]+lev]-1);
    if(du[now]==1){
        f[g]=min(f[g],lev-cnt1[v[now]-lev]);
        f[g]=min(lev-cnt2[v[now]+lev],f[g]);
        f[g]=min(f[g],acu);
        return;
    }
    for(int x:mp[now]){
        if(x==fa)continue;
        if(du[x]>2)return;
        dfs2(x,now,lev+1,acu+1,g);
    }
}
void dfs(int now,int fa,int lev){
    if(now==1&&du[now]==2){
        cnt1[v[now]-lev]++;
        cnt2[v[now]+lev]++;
        for(int x:mp[now]){
            if(x==fa)continue;
            if(x==ff[now])continue;
            dfs2(x,now,lev+1,f[now]+1,now);
        }
        return;
    }
    else if(now==1&&du[now]>1){
        return;
    }
    else if(du[now]>2){
        if(du[now]==3){
            cnt1[v[now]-lev]++;
            cnt2[v[now]+lev]++;
            for(int x:mp[now]){
                if(x==fa)continue;
                if(x==ff[now])continue;
                dfs2(x,now,lev+1,f[now]+1,now);
            }
        }
        return;
    }
    f[now]=f[fa]+1;
    f[now]=min(f[now],lev-cnt1[v[now]-lev]-1);
    f[now]=min(f[now],lev-cnt2[v[now]+lev]-1);
    cnt1[v[now]-lev]++;
    cnt2[v[now]+lev]++;
    for(int x:mp[now]){
        if(x==fa)continue;
        dfs(x,now,lev+1);
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
    while(t--){
        int n;
        cin>>n;
        f[0]=-1;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            mp[i].clear();
            du[i]=0;
            f[i]=-1;
        }
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
            du[x]++,du[y]++;
        }
        dfs1(1,0);
        for(int i=2;i<=n;i++){
            if(du[i]==1){
                f[i]=0;
                dfs(i,0,1);
            }
            cnt1.clear();
            cnt2.clear();
        }
        for(int i=1;i<=n;i++){
            cout<<f[i]<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}