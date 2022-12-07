#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=998244353;
int a[N];
ll f[N][2];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(f,0,sizeof(ll)*((n+5)*2));
        f[0][0]=1;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[a[i]+1][0]=(f[a[i]+1][0]*2)%mod;
            f[a[i]+1][0]=(f[a[i]+1][0]+f[a[i]][0])%mod;
            if(a[i]>0){
                f[a[i]-1][1]=(f[a[i]-1][1]*2)%mod;
                f[a[i]-1][1]=(f[a[i]-1][1]+f[a[i]-1][0])%mod;
            }
            f[a[i]+1][1]=(f[a[i]+1][1]*2)%mod;
        }
        for(int i=1;i<=n+1;i++){
            ans=((ans+f[i][0])%mod+f[i][1])%mod;
        }
        ans=(ans+f[0][1])%mod;
        cout<<ans%mod<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}