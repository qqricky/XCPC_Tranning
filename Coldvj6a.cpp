#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#define ll long long
const int N=1e5+10; 
using namespace std;
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
int jiechen[100000];
int mod;
void pre_work(int n,int mod)
{
    jiechen[1]=1;
    for(int i=2;i<=n;i++){
        jiechen[i]=(jiechen[i-1]*i)%mod;
    }
}
ll C(ll n,ll m,ll p)                                                 /*组合数*/ 
{
    ll a=1,b=1;
    if (m>n) return 0;
    while (m)
    {
        a=(a*n)%p;
        b=(b*m)%p;
        --m;                                                    
        --n;        
    }
    return ( (ll)a * (ll)pow_Q(b,p-2,p) )%p;  
}
ll lucas(ll n,ll m,ll p)
{
    if(m==0)return 1;
    ll ans=0;
    ans=(ll)C(n%p,m%p,p)*(ll)lucas(n/p,m/p,p)%p;
    return ans;
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
    while(t--)
    {
        ll n,m,p;
        cin>>n>>m>>p;
        cout<<lucas(n+m,m,p)<<endl;
    }
    //system("pause");
    return 0;
}