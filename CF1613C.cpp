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
ll a[N];
int n;
ll h;
inline bool ck(ll x){
    ll tot=x;
    for(int i=2;i<=n;i++){
        tot+=min(a[i]-a[i-1],x);
    }
    if(tot>=h)return 1;
    return 0;
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
    while(t--){
        cin>>n>>h;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll l=0,r=1e18;
        while(l<r){
            ll mid=(l+r)>>1ll;
            if(ck(mid))r=mid;
            else l=mid+1;
        }
        cout<<r<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}