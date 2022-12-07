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
bool vis[N]={};
vector<pair<int,ll> >mp[N];
unordered_map<int,int>mpp[N];
unordered_map<int,int>vmp[N];
int tmp[N];
ll num=0;
ll tot=0;
bool flag=1;
void dfs(int now,int fa,ll j,int val){
    vis[now]=1;
    num+=val;
    tmp[now]=val;
    tot++;
    for(auto pr:mp[now]){
        if(pr.first==fa)continue;
        if(vis[pr.first]){
            if((pr.second>>j)&1){
                if(tmp[now]==tmp[pr.first])flag=0;
                return;
            }
            else{
                if(tmp[now]!=tmp[pr.first])flag=0;
                return;
            }
            continue;
        }
        if((pr.second>>j)&1){
            dfs(pr.first,now,j,val^1);
        }
        else{
            dfs(pr.first,now,j,val);
        }
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
    for(int i=1;i<=m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        if(x==y&&w!=0)flag=0;
        if(vmp[x][y]){
            if(mpp[x][y]!=w)flag=0;
            else{
                continue;
            }
        }
        mp[x].push_back(make_pair(y,w));
        mpp[x][y]=w;
        vmp[x][y]=1;
        if(vmp[y][x]){
            if(mpp[y][x]!=w)flag=0;
            else{
                continue;
            }
        }
        mpp[y][x]=w;
        vmp[y][x]=1;
        mp[y].push_back(make_pair(x,w));
    }
    ll ans=0;
    for(int j=0;j<=40;j++){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                num=0,tot=0;
                dfs(i,0,j,0);
                num=min(num,tot-num);
                ans+=1ll*(1ll<<j)*num;
            }
            if(!flag){
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    if(flag)cout<<ans;
    else cout<<-1;
    cout.flush();
    system("pause");
    return 0;
}