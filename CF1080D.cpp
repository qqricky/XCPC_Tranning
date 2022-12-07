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
ll f(ll x){
    return ((1<<(2*x))-1)/2;
}
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
        ll n,k;
        cin>>n>>k;
        ll ans=n;
        ll fac=1;
        ll base=1;
        while(k>0){
            ans--;
            k-=f(ans)*fac+fac;
            base=base*2+1;
            fac=fac*3;
            if(ans<0)break;
        }
        if(ans<0)cout<<"NO\n";
        else cout<<"YES "<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}