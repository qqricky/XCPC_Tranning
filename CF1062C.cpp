#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
const ll mod=1e9+7;
ll powq(ll a,ll b){
    if(b==0)return 1;
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int cnt[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        if(ch-'0'){
            cnt[i]=cnt[i-1]+1;
        }
        else{
            cnt[i]=cnt[i-1];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        int num=cnt[r]-cnt[l-1];
        ll ans=((powq(2,len)-powq(2,len-num))%mod+mod)%mod;
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}