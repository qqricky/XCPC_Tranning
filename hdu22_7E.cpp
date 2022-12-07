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
ll fac[N];
ll ans=0;
ll n,m;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
ll c(ll n,ll m){
    return fac[n]*powq(fac[n-m],mod-2)%mod*powq(fac[m],mod-2)%mod;
}
ll add(ll &a,ll b){
    a=a+b>mod ? a+b-mod : a+b;
}
void dfs(ll now,ll num,ll acu,ll res){
    if(now*now>m)return;
    if(num>n)return;
    if(acu>m)return;
    add(ans,res*c(n+1,num+1)%mod);
    for(ll i=0;acu*powq(now,i)<=m;acu++){
        dfs(now+1,num+i,acu*powq(now,i),res*c(num+i+1,num+1)%mod);
    }
}
void init(){
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    init();
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        dfs(1,0,1,1);
        cout<<ans<<endl;
    }
    cout.flush();
    system("pause");
    return 0;
}