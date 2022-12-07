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
const ll mod=1e9+7;
ll powq(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll f[1070]={};
ll rev=powq(100,mod-2);
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,p;
    cin>>n>>p;
    f[0]=0;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[j]=(f[j]+(1+f[i])*(powq(p,j-i)%mod*powq(100-p,i)%mod*powq(powq(100,j),mod-2)%mod)%mod)%mod;
        }
    }
    cout<<f[n];
    cout.flush();
    system("pause");
    return 0;
}