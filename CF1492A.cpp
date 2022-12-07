#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll gcd(ll a,ll b)
{
    return b? gcd(b,a%b): a;
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int  t;
    cin>>t;
    while(t--)
    {
        ll p;
        ll a[4];
        cin>>p;
        for(int i=1;i<=3;i++)cin>>a[i];
        ll ans=1000000000000000009;
        for(int i=1;i<=3;i++){
            ll k=p-(p/a[i])*a[i];
            if(k==0)ans=0;
            else ans=min(ans,a[i]-k);
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}