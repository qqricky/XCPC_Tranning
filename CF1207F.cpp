#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int f[710][710]={};
ll a[N]={};
ll cnt[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll mx=0;
    // for(int i=1;i<=700;i++){
    //     f[i][0]=500000;
    // }
    for(int i=1;i<=n;i++){
        int tp;
        ll x,y;
        cin>>tp>>x>>y;
        if(tp==1){
            mx=max(mx,x);
            cnt[x]+=y;
            for(int j=1;j<=700;j++){
                f[j][x%j]+=y;
            }
        }
        else{
            ll ans=0;
            if(x>700){
                for(ll j=y;j<=mx;j+=x){
                    ans+=cnt[j];
                }
            }
            else{
                ans=f[x][y];
            }
            cout<<ans<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}