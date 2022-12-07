#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll fac[N];
const ll mod=1000000007;
ll c[300][300];
void init(){
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=250;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
ll powq(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
// ll c(ll n,ll m){
//     if(m==0)return 1;
//     if(n<m)return 0;
//     return fac[n]*powq(fac[n-m],mod-2)%mod*powq(fac[m],mod-2)%mod;
// }
ll f[750][750]={};

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    init();
    cin>>n>>k;
    if(n==1){
        cout<<1;
        return 0;
    }
    f[0][n]=1;
    double t=((double)clock()/CLOCKS_PER_SEC);
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            f[i][j]=f[i-1][j]*(((powq(k,n-j)-powq(k-1,n-j))%mod+mod)%mod)%mod*powq(k-1,j)%mod;
            for(int x=j+1;x<=n;x++){
                f[i][j]=(f[i][j]+f[i-1][x]*c[x][x-j]%mod*powq(k-1,j)%mod*powq(k,n-x)%mod)%mod;
            }
            //cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
        }
    }
    //cout<<((double)clock()/CLOCKS_PER_SEC)-t<<endl;
    cout<<f[n][0]%mod;
    cout.flush();
    //system("pause");
    return 0;
}