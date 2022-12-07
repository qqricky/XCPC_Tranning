#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5070;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll fac[N];
ll hs[N];
const ll base=13331;
const ll mod=1e9+7;
int s[N];
ll powq(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll ifac[N]={};
ll gethash(int l,int r){
    return ((hs[r]-hs[l-1]*fac[r-l+1])%mod+mod)%mod*ifac[l-1]%mod;
}
int n;
void init(){
    fac[0]=1;
    for(int i=1;i<=N;i++){
        fac[i]=fac[i-1]*base%mod;
    }
    hs[0]=0;
    ifac[0]=1;
    ifac[1]=powq(fac[1],mod-2);
    for(int i=2;i<=n;i++){
        ifac[i]=ifac[i-1]*ifac[1]%mod;
    }
    for(int i=1;i<=n;i++){
        s[i]++;
        hs[i]=(hs[i-1]*base%mod+s[i])%mod;
    }
}
unordered_map<ll,int>mp;
int ss[N];
bool vis[N];
int num[N]={};
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
        int q;
        cin>>n>>q;
        memset(vis,0,sizeof(bool)*(q));
        for(int i=1;i<=n;i++)cin>>s[i];
        init();
        int cnt=0;
        for(int i=1;i<=q;i++){
            int sz;
            cin>>sz;
            ll ha=0;
            for(int j=1;j<=sz;j++){
                cin>>ss[j];
                ss[j]++;
            }
            for(int j=sz;j>=1;j--){
                ha=(ha*base%mod+ss[j])%mod;
            }
            mp[ha]=i;
        }
        for(int len=1;len<=n;len++){
            memset(num,0,sizeof(int)*(n+1));
            cnt=0;
            for(int j=1;j<=len;j++){
                num[s[j]]++;
                if(num[s[j]]==2)cnt++;
            }
            for(int r=len;r<=n;r++){
                if(cnt==0){
                    int k=mp[gethash(r-len+1,r)];
                    if(k){
                        vis[k]=1;
                    }
                }
                num[s[r+1]]++;
                if(num[s[r+1]]==2)cnt++;
                num[s[r-len+1]]--;
                if(num[s[r-len+1]]==1)cnt--;
            }
        }
        for(int i=1;i<=q;i++){
            if(vis[i])cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    cout.flush();
    system("pause");
    return 0;
}