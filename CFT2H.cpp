#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
ll jie[N];
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
    int t;
    cin>>t;
    jie[1]=1;
    jie[0]=1;
    for(int i=1;i<=200002;i++)jie[i]=(jie[i-1]*i)%mod;
    while(t--)
    {
        int n;
        cin>>n;
        n--;
        cout<<((jie[2*n+1])*inv(jie[n]*jie[n+1])%mod)<<"\n";
    }
    cout<<endl;
    //system("pause");
    return 0;
} 