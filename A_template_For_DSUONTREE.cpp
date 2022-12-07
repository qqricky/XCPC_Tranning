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
int n;
vector<int>mp[N];
int sz[N],son[N];
int cor[N],cnt[N];
bool skip[N];
ll mx,now,ans[N];
void getsize(int u,int fa){
    sz[u]=1;
    for(auto v:mp[u]){
        if(v==fa)continue;
        getsize(v,u);
        if(sz[v]>sz[son[u]])son[u]=v;
        sz[u]+=sz[v];
    }
}
void add(int u,int fa,int val){
    cnt[cor[u]]+=val;
    if(val>0){
        if(cnt[cor[u]]>mx)now=cor[u],mx=cnt[cor[u]];
        else if(cnt[cor[u]]==mx)now+=cor[u];
    }
    for(auto v:mp[u]){
        if(v==fa||skip[v])continue;
        add(v,u,val);
    }
}
void dfs(int u,int fa,bool keep){
    for(auto v:mp[u]){
        if(v==fa||v==son[u])continue;
        dfs(v,u,0);
    }
    if(son[u])dfs(son[u],u,1),skip[son[u]]=1;
    add(u,fa,1);
    ans[u]=now;
    if(son[u])skip[son[u]]=0;
    if(!keep)add(u,fa,-1),mx=now=0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>cor[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    getsize(1,0);
    dfs(1,0,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout.flush();
    system("pause");
    return 0;
}