#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll n,k;
ll dp[2][110][2070]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    ll ans=0;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        ll v,t;
        cin>>v>>t;
        int now=i&1;
        int pre=now^1;
        for(int kk=0;kk<=k;kk++){
            for(int j=0;j<=1500;j++){
                dp[now][kk][j]=dp[pre][kk][j];
            }
            for(ll j=0;j<=1500;j++){
                ll x1=abs(j-t);
                ll x2=abs(j+t);
                dp[now][kk][x1]=max(dp[now][kk][x1],dp[pre][kk][j]+v);
                dp[now][kk][x2]=max(dp[now][kk][x2],dp[pre][kk][j]+v);
                if(kk>0){
                    x1=abs(j-2*t);
                    x2=abs(j+2*t);
                    dp[now][kk][x1]=max(dp[now][kk][x1],dp[pre][kk-1][j]+v);
                    dp[now][kk][x2]=max(dp[now][kk][x2],dp[pre][kk-1][j]+v);
                }
            }
            ans=max(ans,dp[now][kk][0]);
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}