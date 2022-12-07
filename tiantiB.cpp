#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
const ll mod=1e9+7;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a; 
}
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //system("pause");
    return 0;
}