#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll calc(ll x)
{
    ll tmp=x;
    ll sum=0;
    while(tmp)
    {
        sum+=tmp%10;
        tmp/=10;
    }
    ll ans=gcd(sum,x);
    if(ans==1)return 0;
    else return x;
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
        ll k=calc(x);
        while(!k)
        {
            x++;
            k=calc(x);
        }
        cout<<k<<"\n";
    }
    //system("pause");
    return 0;
}