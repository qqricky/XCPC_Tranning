#include <iostream>
#include <cmath>
#include <string>
#define ll long long
const int N=1e5+10; 
using namespace std;
const int mo=9973;
ll pow_Q(ll a,ll b,int mod)
{
    ll ans=1;
    ll base=a;
    while(b!=0)
    {
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
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
        ll n,b;
        cin>>n>>b;
        cout<<(n*pow_Q(b,mo-2,mo))%mo<<endl;
    }
    //system("pause");
    return 0;
}