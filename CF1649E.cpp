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
int c[N]={};
int lowbit(int x) {
  return x & -x;
}
void add(int x, int k) {
  while (x <= 2e5) { 
    c[x] = c[x] + k;
    x = x + lowbit(x);
  }
}
int getsum(int x) {
  int ans = 0;
  while (x >= 1) {
    ans = ans + c[x];
    x = x - lowbit(x);
  }
  return ans;
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
ll num[N]={};
ll sum[N]={};
int t[N];
ll fac[N];
ll ifac[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    fac[0]=1;
    for(int i=1;i<=2e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    ifac[200000]=powq(fac[200000],mod-2);
    for(int i=200000-1;i>=1;i--){
        ifac[i]=(ifac[i+1]*(i+1))%mod;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(x,1);
        num[x]++;
    }
    for(int i=1;i<=m;i++)cin>>t[i];
    ll ans=0;
    ll acu=1;
    for(int i=1;i<=2e5;i++){
        if(num[i]){
            acu=(acu*ifac[num[i]])%mod;
        }
    }
    int k=min(n,m);
    int i;
    for(i=1;i<=k;i++){
        int num2=getsum(t[i]-1);
        int num1=num[t[i]];
        if(num2<=0&&num1<=0)break;
        ans=(ans+num2*acu%mod*fac[n-i]%mod)%mod;
        if(num1==0)break;
        add(t[i],-1);
        num[t[i]]--;
        if(num[t[i]]){
            acu=(acu*fac[num[t[i]]+1]%mod*ifac[num[t[i]]])%mod;
        }
    }
    if(n<m&&i>k){
        ans=(ans+1)%mod;
    }
    cout<<ans%mod;
    cout.flush();
    //system("pause");
    return 0;
}