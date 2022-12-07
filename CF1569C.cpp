#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=998244353;
ll jie[N];
int a[N];
ll pow_q(ll a,ll b)
{
    ll ans=1,base=a;
    while(b)
    {
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
void init()
{
    jie[0]=1;
    for(int i=1;i<=2e5;i++){
        jie[i]=(jie[i-1]*i)%mod;
    }
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
    init();
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        if(a[n]-a[n-1]>1){
            cout<<0<<'\n';
            continue;
        }
        if(a[1]==a[n]||a[n]==a[n-1]){
            cout<<jie[n]<<'\n';
            continue;
        }
        int cntt=0;
        int pos=n-1;
        int ma=a[pos];
        while(a[pos]==ma){
            pos--;
            cntt++;
        }
        ll ans=jie[n]-jie[cntt]*jie[n-cntt-1]%mod*jie[n]%mod*pow_q(jie[n-cntt-1]*jie[cntt+1]%mod,mod-2)%mod;
        ans=(ans%mod+mod)%mod;
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}