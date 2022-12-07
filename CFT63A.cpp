#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
const ll mod=1e9+7;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
ll fac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=fac[i-1]*i%mod;
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        ll acu=1;
        for(ll i=1,j=n;i<=k-1;i++,j--){
            acu=(acu*j)%mod;
            ans=(ans+acu*powq(fac[i],mod-2)%mod)%mod;
        }
        ans=(((powq(2,n)-1)-ans)%mod+mod)%mod;
        cout<<"Case #"<<cas<<": "<<ans<<"\n";
    }
    // cout.flush();
    // system("pause");
    return 0;
}