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
const ll mod=1e9+7;
ll g[N]={};
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
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
    ll ans=0;
    g[1]=1;
    g[2]=6;
    g[3]=20;
    for(int i=4;i<=N;i++){
        g[i]=(powq(2,i-1)%mod+2*g[i-1]%mod+4*g[i-2]%mod)%mod;
    }
    for(int i=2;i<=n-1;i++){
        ans=(ans+powq(2,n-i)*4%mod*g[i-1]%mod)%mod;
        ans=(ans+powq(2,i-1)*4%mod*g[n-i])%mod;
    }
    for(int i=1;i<=10;i++)cout<<g[i]<<',';
    // cout<<(ans+4*g[n]%mod)%mod;
    cout.flush();
    system("pause");
    return 0;
}