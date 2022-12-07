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
vector<int>mp[N];
vector<int>imp[N];
bool vis[N]={};
bool vis1[N]={};
bool vis2[N]={};
int a[N];
void dfs1(int now){
    if(vis[now])return;
    vis1[now]=1;
    vis[now]=1;
    for(int v : mp[now]){
        dfs1(v);
    }
}
void dfs2(int now){
    if(vis[now])return;
    vis2[now]=1;
    vis[now]=1;
    if(a[now]==1)return;
    for(int v : imp[now]){
        dfs2(v);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        imp[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            dfs1(i);
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(a[i]==2){
            dfs2(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis1[i]&&vis2[i])cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}