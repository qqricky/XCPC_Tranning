#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5070;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int a[N];
ll f[N][N];
ll num[N];
ll sum[N];
ll sum2[N];
ll acu[N];
ll sum3[N];
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
inline void add(ll &a,ll b){
    a= a+b>mod ? a+b-mod : a+b;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,kk,r;
        cin>>n>>kk>>r;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            num[i]=0;
            acu[i]=0;
        }
        acu[n+1]=1;
        for(int i=n;i>=1;i--){
            int pos=upper_bound(a+1,a+n+1,a[i]-r)-a-1;
            num[i]=pos;
            acu[i]=(acu[i+1]*num[i])%mod;
            pos=lower_bound(a+1,a+n+1,a[i]+r)-a;
            sum3[i]=(n-pos+1);
        }
        for(int i=0;i<=n+1;i++){
            sum[i]=0;
            sum2[i]=0;
            for(int j=0;j<=n+1;j++){
                f[i][j]=0;
            }
        }
        f[n+1][0]=1;
        int cnt=0;
        int ptr=n+1;
        ll tmp=1;
        a[n+1]=a[n]+r;
        for(int i=n;i>=1;i--){
            while(a[ptr]-a[i]>r){
                // cout<<i<<' '<<ptr<<endl;
                if(ptr!=n+1)
                tmp=tmp*powq(num[ptr],mod-2)%mod;
                for(int k=1;k<=kk;k++){
                    add(sum[k],f[ptr][k]);
                }
                ptr--;
            }
            if(i!=n)
            tmp=(tmp*(num[i+1]))%mod;
            for(int k=1;k<=kk;k++){
                sum[k]=(sum[k]*num[i+1])%mod;
                // add(sum[k],(sum[k]*num[i])%mod);
            }
            if(a[ptr-1]-a[i]>=r){
                ptr--;
                // cout<<i<<' '<<ptr<<endl;
                for(int k=1;k<=kk;k++){
                    add(sum[k],f[ptr][k]);
                }
            }
            f[i][0]=acu[i];
            for(int k=1;k<=kk;k++){
                // if(i==3&&k==1){
                //     cout<<ptr<<' '<<tmp<<endl;
                // }
                // if(k==1)add(f[i][k],acu[i+1]);
                add(f[i][k],f[i+1][k-1]);
                add(f[i][k],f[ptr][k]*tmp%mod);
                // else add(f[i][k],sum2[k-1]);
                // add(f[i][k],sum[k]);
            }
            for(int k=1;k<=kk;k++){
                sum2[k]=(sum2[k]*num[i])%mod;
                // add(sum2[k],(sum2[k]*num[i])%mod);
                add(sum2[k],f[i][k]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=kk;j++){
                std::cout<<i<<':'<<j<<' '<<f[i][j]<<endl;
            }
        }
        std::cout<<f[1][kk]<<'\n';
    }
    std::cout.flush();
    std::system("pause");
    return 0;
}