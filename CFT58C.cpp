#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=6e5+10;
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
vector<int>mp[N];
int dis[N];
int dis2[N];
int dep[N];
int f[N][25];
ll fac[N];
int cnt[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=2e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll c(ll n,ll m){
    if(m>n)return 0;
    return powq(fac[n-m],mod-2)*powq(fac[m],mod-2)%mod*fac[n]%mod;
}
void dfs(int x,int pa){
    for(int y:mp[x]){
        if(y==pa)continue;
        f[y][0]=x;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
int lca(int x,int y){
    if(dep[y]<dep[x])swap(x,y);
    for(int j=20;j>=0;j--){
        int ne=f[y][j];
        if(dep[ne]>=dep[x]){
            y=ne;
        }
    }
    if(x==y)return x;
    for(int j=20;j>=0;j--){
        if(f[x][j]==f[y][j])continue;
        x=f[x][j];
        y=f[y][j];
    }
    return f[x][0]==0 ? 1 : f[x][0];
}
void getdis(int now,int pa){
    for(int x:mp[now]){
        if(x==pa)continue;
        getdis(x,now);
        dis[now]+=dis[x];
        dis2[now]+=dis2[x];
    }
}
ll ans=0;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=0;i<=n;i++){
            mp[i].clear();
            dis[i]=0;
            dis2[i]=0;
            dep[i]=0;
            f[i][0]=0;
            cnt[i]=0;
        }
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        dfs(1,0);
        for(int j=1;j<=20;j++){
            for(int i=1;i<=n;i++){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            if(x==y){
                dis2[x]++;
                dis2[f[x][0]]--;
                continue;
            }
            dis2[x]++;
            dis2[y]++;
            int tmp=lca(x,y);
            // cout<<x<<' '<<y<<' '<<lca(x,y)<<endl;
            dis2[tmp]--;
            dis2[f[tmp][0]]--;
            dis[x]++;
            dis[y]++;
            dis[tmp]-=2;
        }
        getdis(1,0);
        ll ans=0;
        for(int i=1;i<=n;i++){
            // cout<<i<<' '<<dis[i]<<' '<<dis2[i]<<endl;
            ll sum=0;
            for(int y:mp[i]){
                if(y==f[i][0]){
                    continue;
                }
                sum+=dis[y];
            }
            ll raw=ans;
            ans=(ans+c(sum-dis[i],k))%mod;
            ll val=dis2[i]-dis[i];
            for(int j=1;j<=k-1;j++){
                if(j>val)break;
                ans=(ans+c(val,j)*c(dis[i],k-j))%mod;
            }
            // cout<<i<<' '<<ans-raw<<endl;
            // ans=(ans+c(sum,k))%mod;
            // ans=(ans-acu+mod)%mod;
            // for(int y:mp[i]){
            //     if(y==f[i][0]){
            //         ll tmp=acu;
            //         ans=(ans+c(sum,k)-tmp)%mod;
            //     }else{
            //         ll tmp=acu-c(dis[y],k);
            //         ans=(ans+c(sum,k)-tmp)%mod;
            //     }
            // }
        }
        cout<<ans%mod<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}