#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
vector<int>G[N];
int size[N],son[N];
bool skip[N];
int n,k,cor[N],cnt[N];
ll mx,now,ans[N];
int a[N];
int ne[N];
unordered_map<int,int>to;
int save[N];
int dep[N];
void getsize(int u,int fa){
    size[u]=1;
    for(auto v:G[u]){
        if(v==fa){
            continue;
        }
        getsize(v,u);
        if(size[v]>size[son[u]])son[u]=v;
        size[u]+=size[v];
    }
}
void add(int u,int fa,int val){
    cnt[cor[u]]+=val;
    if(val>0){
        if(cnt[cor[u]]>mx)now=cor[u],mx=cnt[cor[u]];
        else if(cnt[cor[u]]==mx)now+=cor[u];
    }
    for(auto v:G[u]){
        if(v==fa||skip[v]){
            continue;
        }
        add(v,u,val);
    }
}
void dfs(int u,int fa,bool keep){
    for(auto v:G[u]){
        if(v==fa||son[u])continue;
        dfs(v,u,0);
    }
    if(son[u])dfs(son[u],u,1),skip[son[u]]=1;
    add(u,fa,1);
    if(son[u])skip[son[u]]=0;
    if(!keep)add(u,fa,-1),mx=now=0;
}
void dfss(int u,int fa,int dp){
    dep[u]=dp;
    for(int v:G[u]){
        if(v==fa)continue;
        dfss(v,u,dp+1);
    }
}
void solve(){
    getsize(1,0);
    dfs(1,0,0);
}
void change(int x,int val){

}
int ask(int x,int y){

}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int ncnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        save[++ncnt]=a[i];
    }
    sort(save+1,save+ncnt+1);
    int ncnt=unique(save+1,save+ncnt+1)-save;
    for(int i=1;i<ncnt;i++){
        to[save[i]]=i;
    }
    change(n+1,n+1);
    for(int i=n;i>=1;i--){
        ne[i]=ask(to[i],1e6);
        G[i].push_back(ne[i]);
        G[ne[i]].push_back(i);
        change(to[a[i]],i);
    }
    solve();
    for(int i=n-k+1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout.flush();
    system("pause");
    return 0;
}