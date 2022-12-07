#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
ll pow_Q(ll a,ll b)
{
    ll ans=1,base=a;
    while(b){
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char ch;
        ll cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ch;
                if(ch=='#'){
                    cnt++;
                }
            }
        }
        ll ans=pow_Q(2,cnt);
        if(cnt==n*m)ans--;
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}