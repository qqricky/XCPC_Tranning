#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll p=1e9+7;
const ll mod=998244353;
ll base=131;
int n;
string str;
ll ans=0;
ll f[N];
// map<pair<ll,ll>,bool>vis;
ll dfs(int now){
    if(now*2>(1ll<<n)-1){
        f[now]=1;
        return str[now];
    }
    ll f1=dfs(now*2);
    ll f2=dfs(now*2+1);
    if(f1==f2){
        f[now]=f[now*2]*f[now*2+1]%mod;
    }
    else{
        f[now]=f[now*2]*2%mod*f[now*2+1]%mod;
    }
    // cout<<now<<'\n';
    // cout<<f1<<' '<<f2<<"\n";
    // cout<<f[now]<<' '<<f[now*2]<<' '<<f[now*2+1]<<endl;
    // if(!vis[make_pair(str[now],(f1*base%p+f2)%p*base%p)]){
    //     ans=(ans+f[now])%mod;
    // }
    // vis[make_pair(str[now],(f1*base%p+f2)%p*base%p)]=1;
    return ((f1*base*base*base%p+f2)%p*base%p+str[now])%p;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>str;
    str=' '+str;
    dfs(1);
    cout<<f[1];
    cout.flush();
    system("pause");
    return 0;
}