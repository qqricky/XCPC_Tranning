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
const ll mod=998244353;
ll fac[N]={};
void init(){
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=fac[i-1]*i%mod;
    }
}
ll powq(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll c(ll n,ll m){
    if(n<m)return 0;
    return fac[n]*powq(fac[n-m],mod-2)%mod*powq(fac[m],mod-2)%mod;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin>>n;
    cout<<(c(n,n/2)-c(n,n/2-1)+mod)%mod;
    cout.flush();
    //system("pause");
    return 0;
}