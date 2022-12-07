#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1000000007;
ll powq(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
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
    ll x,n;
    cin>>x>>n;
    ll ans=1;
    set<ll>s;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            while(x%i==0)x/=i;
            s.insert(i);
        }
    }
    if(x>1)s.insert(x);
    for(ll p:s){
        __int128 pp=p;
        ll ori=p;
        while(pp<=n){
            ans=(ans*powq(ori,n/p))%mod;
            p*=ori;
            pp*=ori;
        }
    }
    cout<<ans%mod;
    cout.flush();
    //system("pause");
    return 0;
}