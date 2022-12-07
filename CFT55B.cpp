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
ll f[N];
ll g[N];
ll up[N];
int a[N];
ll lim[60][60];
int num[60];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(lim,0,sizeof(lim));
        ll ans=1ll<<n;
        ans--;
        // for(int i=1;i<=n;i++){
        //     f[i]=1;
        //     up[i]=1;
        //     for(int j=1;j<i;j++){
        //         if(a[i]<a[j])f[i]+=f[j];
        //         else up[i]+=up[j];
        //     }
        // }
        // for(int i=n;i>=1;i--){
        //     g[i]=1;
        //     for(int j=n;j>i;j--){
        //         if(a[j]>a[i])f[i]+=f[j];
        //     }
        // }
        // for(int i=1;i<=n;i++)ans+=f[i]*g[i];
        // cout<<'!'<<" "<<ans<<'\n';
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<i;j++){
        //         if(a[j]<a[i])
        //         lim[i][a[j]]+=up[j];
        //     }
        //     for(int k=1;k<=50;k++){
        //         lim[i][k]+=lim[i][k-1];
        //     }
        //     for(int j=i+1;j<=n;j++){
        //         if(a[j]<a[i])
        //         ans+=lim[i][a[j]-1];
        //     }
        // }
        int cntt=0;
        for(int i=2;i<n;i++){
            int cnt=0;
            memset(num,0,sizeof(num));
            for(int j=1;j<i;j++)num[a[j]]++;
            for(int j=1;j<=50;j++)num[j]+=num[j-1];
            for(int k=n;k>i;k--){
                if(a[k]<a[i]){
                    int x=a[k];
                    ll val=1ll<<(n-i-cnt-1);
                    cnt++;
                    int y=num[a[i]]-num[x];
                    ll res=((1ll<<(y))-1)*(1ll<<(i-1-y))*val;
                    ans-=res;
                    // cout<<((1ll<<(y))-1)*(1ll<<(i-1-y))*val<<'\n';
                }
            }

        }
        cout<<ans<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}