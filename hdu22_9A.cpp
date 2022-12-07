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
const ll mod=998244353;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
ll a[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        ll ans1=0;
        ll val=a[1];
        for(int i=2;i<=n;i++){
            val=((val+a[i])+val*a[i]%mod)%mod;
        }
        ll val2=a[n];
        for(int i=n-1;i>=1;i--){
            val2=((val2+a[i])+val2*a[i]%mod)%mod;
        }
        cout<<(val+val2)%mod*powq(2,mod-2)%mod<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}