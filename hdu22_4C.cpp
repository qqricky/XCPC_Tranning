#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=570+10;
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
ll n,m;
ll f[2][N][N];
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll a[N];
int can[N];
unordered_map<ll,int>is;
inline void add(ll &a,ll b){
    a= (a+b >= mod) ? a+b-mod : a+b;
}
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
        cin>>n>>m;
        is.clear();
        can[0]=0;
        for(int i=1;i<=n;i++){
            can[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>0){
                is[a[i]]++;
            }else if(a[i]<0){
                can[i]=is[-a[i]];
            }
        }
        for(int k=0;k<=1;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    f[k][i][j]=0;
                }
            }
        }
        f[0][0][0]=1;
        for(int i=1;i<=n;i++){
            int now=i&1;
            int pre=now^1;
            for(int j=0;j<=i;j++){
                for(int k=0;k<=i;k++){
                    if(j<k)continue;
                    f[now][j][k]=0;
                    if(a[i]==0){
                        if(j>0)add(f[now][j][k],f[pre][j-1][k]);
                        add(f[now][j][k],f[pre][j+1][k]*m%mod);
                        add(f[now][j][k],f[pre][j+1][k+1]);
                    }else{
                        if(a[i]>0){
                            if(j>0)
                            add(f[now][j][k],f[pre][j-1][k-1]);
                        }else{
                            if(can[i]){
                                add(f[now][j][k],f[pre][j+1][k]);
                                add(f[now][j][k],f[pre][j+1][k+1]);
                                f[now][j][k]=(f[now][j][k]-can[i]+mod)%mod;
                            }
                            else{
                                add(f[now][j][k],f[pre][j+1][k]%mod);
                            }
                        }
                    }
                }
            }
        }
        cout<<f[n&1][0][0]%mod<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}