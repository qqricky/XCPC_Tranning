#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(3)
const int N=1e6+5;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=998244353;
ll pre[N];
ll f[64][5];
ll sum[64][64][5];
ll cnt[64]={};
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
ll fac[N];
ll rev;
ll c(ll n,ll m){
    if(n<m)return 0;
    return pre[n];
    // return fac[n]*powq(fac[n-m],mod-2)%mod*powq(fac[m],mod-2)%mod;
}
char str[N];
inline int conv(int pos){
    char ch=str[pos];
    if(ch>='A'&&ch<='Z'){
        return ch-'A'+11;
    }
    if(ch>='0'&&ch<='9'){
        return ch-'0'+1;
    }
    return ch-'a'+37;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    fac[0]=1;
    rev=powq(2,mod-2);
    // for(int i=1;i<=1e6;i++){
    //     fac[i]=(fac[i-1]*i)%mod;
    // }
     str[0]='s';
	scanf("%s",str+1);
    int n=strlen(str);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int now=conv(i);
        // for(int j=1;j<=62;j++){
        //     if(j==now)continue;
        //     g[now][j]=(g[now][j]+cnt[j])%mod;
        // }
        cnt[now]++;
    }
    for(ll asd=1;asd<=N-4;asd++){
    	pre[asd]=asd*(asd-1)%mod*rev%mod;
	}
    for(int i=n;i>=1;i--){
        int now=conv(i);
        // for(int j=1;j<=62;j++){
        //     if(j==now)continue;
        //     g[j][now]=(g[j][now]-cnt[j]+mod)%mod;
        // }
        cnt[now]--;
        for(int j=1;j<=62;j++){
            if(j==now)continue;
            f[j][1]=1;
            for(int k=2;k<=4;k++){
                f[j][k]=sum[j][now][k-1];
            }
        }
        ll tot=0;
        ll val=0;
        for(int j=1;j<=62;j++){
            if(j!=now){
                tot+=cnt[j];
            }
            val=val+c(cnt[j],2);
        }
        val%=mod;
        for(int j=1;j<=62;j++){
           if(j==now)continue;
            if(f[j][4]==0)continue;
            ll tmp=c(i-1,2);
            if(tmp==0)continue;
            tot-=cnt[j];
            ll va=0;
            va+=cnt[now]*tot;
            va+=tot*cnt[j];
            va+=cnt[j]*cnt[now];
            // tmp=(tmp-tot*cnt[now]%mod+mod)%mod;
            // tmp=(tmp-tot*cnt[j]%mod+mod)%mod;
            // tmp=(tmp-cnt[j]*cnt[now]%mod+mod)%mod;
            tot+=cnt[j];
            va+=val;
            tmp=(tmp-va%mod+mod)%mod;
            ans=(ans+tmp*f[j][4])%mod;
        }
        for(int j=1;j<=62;j++){
            for(int k=1;k<=4;k++){
                sum[now][j][k]=((sum[now][j][k]+f[j][k]>mod ? sum[now][j][k]+f[j][k]-mod : sum[now][j][k]+f[j][k]));
            }
        }
    }
    printf("%lld\n",ans);
    // system("pause");
    return 0;
}
