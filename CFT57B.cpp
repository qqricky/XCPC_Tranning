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
ll powq(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res=(res*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return res;
}
ll f[N];
ll g[N];
ll x[N],a[N];
ll h[N];
ll val[N];
map<ll,ll>cnt;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        cnt.clear();
        int ncnt=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>x[i];
            cnt[a[i]]+=x[i];
        }
        if(cnt[0]){
            a[++ncnt]=0;
            x[ncnt]=cnt[0];
            cnt[0]=0;
        }
        for(auto pr:cnt){
            if(pr.second==0)continue;
            a[++ncnt]=pr.first;
            x[ncnt]=pr.second;
        }
        a[ncnt+1]=INF;
        f[ncnt]=1;
        g[ncnt]=x[ncnt];
        for(int i=ncnt-1;i>=1;i--){
            ll dis=a[i+1]-a[i];
            if(dis>=30||x[i]<powq(2,dis)){
                g[i]=(x[i])*((f[i+1]+g[i+1])%mod)%mod;
                f[i]=(f[i+1]+g[i+1])%mod;
            }else{
                g[i]=(x[i]-powq(2,dis))*(f[i+1])%mod;
                g[i]=(g[i]+(powq(2,dis))*((f[i+1]+g[i+1])%mod)%mod)%mod;
                f[i]=(f[i+1])%mod;
            }
        }
        cout<<"Case #"<<cas<<": ";
        cout<<(f[1]+g[1])%mod<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}