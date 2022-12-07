#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
ll f[66][66]={};
ll mod=1e9+7;
ll pow_Q(ll a,ll b,ll mod)
{
    ll ans=1,base=a%mod;
    while(b!=0)
    {
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
ll inv(ll x)
{
    return pow_Q(x,mod-2,mod);
}

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<(1ll<<m)+(1ll<<n)-2<<endl;
    //system("pause");
    return 0;
}