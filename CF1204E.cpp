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
ll f[2070][2070]={};
ll fac[5070],ifac[5070];
ll g[2070][2070]={};
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=4000;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    for(int i=4000;i>=0;i--){
        ifac[i]=powq(fac[i],mod-2);
    }
}
ll C(ll n,ll m){
    if(n<m||m<0)return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    f[0][0]=1;
    for(int i=0;i<=max(n,m);i++){
        for(int j=0;j<=max(n,m);j++){
            ll val=i-j;
            if(val<0)continue;
            f[i][j]=((C(i+j,i)-C(i+j,j-1))%mod+mod)%mod;
            g[i+1][j]=f[i][j];
            //cout<<i+1<<' '<<j<<' '<<g[i+1][j]<<'\n';
        }
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=min(i,m);j++){
            ll val=i-j;
            if(m-j-n+i<0)continue;
            ans=(ans+val*g[i][j]%mod*f[m-j][n-i]%mod)%mod;
            // cout<<"!@   : ";
            // cout<<val<<' '<<g[i][j]*f[m-j][n-i]<<'\n';
            // cout<<i<<' '<<j<<'\n';
            // cout<<' '<<g[i][j]<<' '<<f[m-j][n-i]<<'\n';
        }
    }
    cout<<ans%mod;
    cout.flush();
    //system("pause");
    return 0;
}