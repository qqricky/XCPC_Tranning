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
int a[N];
int b[N];
int pos[N];
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
ll fac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=2e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
int cnt[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    init();
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        memset(pos,0,sizeof(int)*(n+5));
        memset(cnt,0,sizeof(int)*(n+5));
        for(int i=1;i<=n;i++)cin>>a[i];
        int num=0;
        set<int>ss;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(b[i]!=-1)pos[b[i]]=i;
            else {
                num++;
                cnt[a[i]]=1;
            }
        }
        // ll ans=fac[num];
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                if(pos[a[i]]){
                    if(a[pos[a[i]]]-a[i]>k){
                        flag=0;
                        break;
                    }
                }else{
                    ss.insert(a[i]);
                }
            }
        }
        for(int i=1;i<=n+1;i++)cnt[i]+=cnt[i-1];
        ll acu=1;
        for(auto x:ss){
            ll val=cnt[n+1]-cnt[min(x+k,n+1)];
            if(num==val)flag=0;
            // cout<<num<<' '<<val<<'\n';
            acu=(acu*(num-val))%mod;
            num--;
        }
        if(flag){
            cout<<acu<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    cout.flush();
    // system("pause");
    return 0;
}