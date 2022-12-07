 #include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
ll fa(int k)
{
    ll base=10;
    k--;
    while(k){
        base*=10;
        k--;
    }
    return base;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    if(k==0)cout<<n;
    else
    cout<<lcm(n,fa(k));
    //system("pause");
    return 0;
}