#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
ll pow_Q(ll a,ll b,ll mod)
{
    ll ans=1,base=a;
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
    int n;
    cin>>n;
    //n have to be a prime
    int p=n;
    for(int i=2;i<=n;i++){
        cout<<"Itself "<<i<<" inv:"<<pow_Q(i,p-2,p)<<" inv'sinv:"<<pow_Q(pow_Q(i,p-2,p),p-2,p)<<endl;
    }
    system("pause");
    return 0;
}