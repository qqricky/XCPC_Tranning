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
const ll mod=1e9+7;
ll a[N];
ll fac[N];
ll gcd(ll a,ll b){
    return b ? a : gcd(b,a%b);
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
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=1;
    for(int i=1;i<n;i++){
        ll val1=a[i];
        ll val2=a[i+1];
        ll tmp=1;
        for(ll j=2;j*j<=val1;j++){
            if(val1%j==0){
                int cnt=0;
                while(val2%j==0){
                    val1/=j;
                    cnt++;
                }
                if(cnt&1){
                    tmp*=j;
                }
            }
        }
        if(val1>1){
            tmp*=val1;
        }
        for(ll j=2;j*j<=val2;j++){
            if(val2%j==0){
                int cnt=0;
                while(val2%j==0){
                    val2/=j;
                    cnt++;
                }
                if(cnt&1){
                    if(tmp%j==0)tmp/=j;
                    else tmp*=j;
                }
            }
        }
        if(val2>1){
            if(tmp%val2==0){
                tmp/=val2;
            }else{
                tmp*=val2;
            }
        }
        fac[i]=tmp;
    }
    for(int i=1;i<n-1;i++){
        ll d=gcd(fac[i],fac[i+1]);
        fac[i+1]/=d;
    }
    for(int i=1;i<n;i++){
        ans=(ans*fac[i])%mod;
    }
    cout<<ans;
    cout.flush();
    system("pause");
    return 0;
}