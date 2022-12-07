#include <bits/stdc++.h>
#define ll long long
const int N=1e6+10; 
using namespace std;
const ll mod=1e9+7;
ll a,b,n;
int ck(ll x)
{
    while(x)
    {
        int z=x%10;
        if(z!=a&&z!=b)return 0;
        x/=10;
    }
    return 1;
}
ll pow_Q(ll a,ll b,ll mod)
{
    ll ans=1;
    ll base=a%mod;
    while(b!=0)
    {
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
ll f[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=1000007;i++)f[i]=f[i-1]*i%mod;
    cin>>a>>b>>n;
    ll ans=0;
    for(int i=0;i<=n;i++){
        if(ck(i*a+(n-i)*b)){
            ans=(ans+f[n]*pow_Q((long long)f[n-i]*f[i],mod-2,mod))%mod;
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}