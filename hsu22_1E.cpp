#pragma GCC optimise(2)
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=998244353;
ll dp[N][22];
ll sum[N][22];
ll pi[N];
inline void prefix_function(string &s) {
    pi[0]=0;
  int n = (int)s.length();
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
}
int x;
string str;
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
        cin>>str;
        cin>>x;
        int n=str.length();
        ll ans=1;
        prefix_function(str);
        int st=0;
        for(int i=0;i<n;i++){
            dp[i][0]=pi[i];
            sum[i][0]=((i+1)%x==0);
        }
        for(int j=1;j<=20;j++){
            for(int i=0;i<n;i++){
                if(dp[i][j-1]-1>0){
                    dp[i][j]=dp[dp[i][j-1]-1][j-1];
                    sum[i][j]=(sum[i][j-1]+sum[dp[i][j-1]][j-1] > mod ? sum[i][j-1]+sum[dp[i][j-1]][j-1]-mod : sum[i][j-1]+sum[dp[i][j-1]][j-1]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<pi[i]<<' ';
        //     // pi[i]++;
        // }
        // cout<<'\n';
        st=x-1;
        for(int i=st;i<n;i++){
            int now=i;
            int half=(i+1)/2;
            ll res=0;
            for(int j=20;j>=0;j--){
                if(dp[now][j]>half){
                    res=(res+sum[now][j]>mod ? res+sum[now][j]-mod : res+sum[now][j]);
                    now=dp[now][j]-1;
                }
            }
            res=(res+sum[now][0]>mod ? res+sum[now][0]-mod : res+sum[now][0]);
            // cout<<i<<' '<<res<<'\n';
            ans=(ans*(res+1))%mod;
        }
        cout<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}