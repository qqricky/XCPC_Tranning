#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
ll pow_q(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll rev=195206359;
ll jie[N];
ll pres[N];
ll inv[N];
ll c(ll n,ll m){
    return jie[n]*inv[n-m]%mod*inv[m]%mod;
}
int nn=5e6;
void init(){
    jie[0]=1;
    for(int i=1;i<=5e6;i++){
        jie[i]=(jie[i-1]*i)%mod;
    }
    inv[nn] = pow_q(jie[nn], mod - 2);
    for (int i = nn - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    pres[0]=1;
    for(int i=1;i<=5e6;i++){
        pres[i]=(pres[i-1]+c(nn,i))%mod;
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
    int n=5e6;
    while (t--)
    {
        int k;
        cin>>k;
        if(k==0){
            cout<<1<<'\n';
            continue;
        }
        cout<<((pow_q(2,n)-pres[k-1])%mod+mod)*rev%mod<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}