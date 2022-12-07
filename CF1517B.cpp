#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll mod;
ll pow_Q(ll a,ll b)
{
    ll ans=1;
    ll base=a;
    while(b)
    {
        if(b&1){
            ans=(ans*base)%mod;
        }
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
        ll x;
        cin>>x;
        if(x%2050){
            cout<<-1<<endl;
            continue;
        }
        else{
            x/=2050;
            int ans=0;
            while(x){
                ans+=x%10;
                x/=10;
            }
            cout<<ans<<endl;
        }
    }
    //system("pause");
    return 0;
}