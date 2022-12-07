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
int fact[N];
ll pow_Q(ll a,ll b)
{
    ll ans=1,base=a%mod;
    while(b){
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
ll C(ll n,ll m,ll p)
{
    if(n<m||m<0)return 0;
    return fact[n]*pow_Q(fact[m],p-2)%p*pow_Q(fact[n-m],p-2)%p;
}
void init()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=N;i++){
        fact[i]=((ll)fact[i-1]*i)%mod;
    }
}
char a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    init();
    while(t--)
    {
        int n;
        read(n);
        for(int i=1;i<=n;i++){
            a[i]=getchar();
        }
        int sum1=0;
        int sum2=0;
        for(int i=1;i<n;i++){
            if(a[i]=='0')sum2++;
            if(a[i]==a[i+1]&&a[i]=='1'){
                sum1++;
                i++;
            }
        }
        sum2+=(a[n]=='0');
        cout<<C(sum1+sum2,sum1,mod)<<endl;
    }
    //system("pause");
    return 0;
}