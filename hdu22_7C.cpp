#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int du[N];
const ll mod=998244353;
vector<int>mp[N];
ll c(ll n,ll m=2){
    return n*(n-1)/2%mod;
}
ll add(ll &a,ll b){
    a= a+b>=mod ? a+b-mod : a+b;
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
        int n;
        cin>>n;
        memset(du,0,sizeof(int)*(n+5));
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            du[x]++,du[y]++;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            //处理每个点作为脖子
            if(du[i]<4)continue;
            ll tmpp=ans;
            ll x=0,y=0,z=0;
            vector<ll>v;
            ll sum=0;
            ll acu=0;
            for(int now:mp[i]){
                //只能作为头 第一类
                if(du[now]==1)x++;
                //能作为头和手 第二类
                else if(du[now]==2)y++;
                //都行 第三类
                else{
                    ll val=du[now]-1;
                    v.push_back(val);
                    add(sum,val);
                    add(acu,c(val,2));
                    z++;
                }
            }
            // sort(v.begin(),v.end());
            for(ll k:v){
                //枚举每一个作为胯
                ll tmp=k*(k-1)/2%mod;
                ll suma=(sum-k+mod)%mod;
                ll acua=(acu-c(k,2)%mod+mod)%mod;
                //两只手都在 第三类
                if(z>2&&x+y+z-3>0){
                    add(ans,tmp*((c(suma,2)-acua+mod)%mod)%mod*(z-3+y+x)%mod);
                }//一只手在 第三类
                if(z>1&&x+y+z-3>0){
                    add(ans,tmp*suma%mod*y%mod*(z-3+x+y)%mod);
                }
                //两只手都在第二类
                if(x+y+z-3>0&&y>=2){
                    add(ans,tmp*c(y,2)%mod*(x+y+z-3)%mod);
                }
            }
        }
        cout<<ans%mod<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}