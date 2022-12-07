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
const ll mod=998244353;
vector<int>mp[N];
ll fac[N];
ll ans=1;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll C(ll n,ll m){
    return fac[n]*powq(fac[m],mod-2)%mod*powq(fac[n-m],mod-2)%mod;
}
bool vis[N]={};
ll pre[N]={};
void dfs(int now,int fa){
    int cnt=0;
    for(int u:mp[now]){
        if(u==fa)continue;
        dfs(u,now);
        if(!vis[u])cnt++;
    }
    if(cnt&1){
        vis[now]=1;
        ans=(ans*cnt%mod*pre[cnt-1]%mod)%mod;
    }
    else{
        ans=(ans*pre[cnt])%mod;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    fac[0]=1;
    pre[1]=1;
    pre[0]=1;
    for(int i=2;i<=1e5;i+=2){
        pre[i]=pre[i-2]*(i-1)%mod;
    }
    for(int i=1;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs(1,0);
    cout<<ans%mod;
    cout.flush();
    //system("pause");
    return 0;
}