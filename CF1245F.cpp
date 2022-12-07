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
ll f[50]={};
ll fac[50]={};
const ll mod=1e9+7;
ll pow_Q(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll C(int n,int m){
    if(m==0)return 1;
    return fac[n]*pow_Q(fac[n-m],mod-2)%mod*pow_Q(fac[m],mod-2)%mod;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=40;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    f[0]=1;
    for(int i=1;i<=30;i++){
        for(int j=0;j<=i;j++){
            f[i]=(f[i]+C(i,j)*pow_Q(2,i-j)%mod)%mod;
        }
    }
}
ll solve(ll x){
    if(x<0)return 0;
    if(x==0)return 2;
    ll ans=0;
    int h=30;
    ll cnt=0;
    while(((x>>h)&1) ==0)h--;
    for(int i=h;i>=0;i--){
        if((x>>i)&1){
            ans=(ans+f[i]*pow_Q(2,cnt)%mod)%mod;
            cnt++;
        }
    }
    ans=(ans+pow_Q(2,cnt))%mod;
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    init();
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        cout<<solve(r)<<' '<<solve(l-1)<<endl;
        cout<<solve(r)-solve(l-1)<<endl;
    }
    cout.flush();
    system("pause");
    return 0;
}