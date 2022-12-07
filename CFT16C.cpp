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
int a[N];
ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll ans=2*(n-1);
    ll anss=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=2*(a[i]-1);
    }
    for(int i=2;i<=n;i++){
        ll tmp=gcd(a[i],a[i-1]);
        if(tmp==1)continue;
        //ll val=max(a[i],a[i-1]);
        ll val=lcm(a[i],a[i-1]);
        ll val1=val/a[i];
        ll val2=val/a[i-1];
        ll tmpp=min(a[i-1]/val1,a[i]/val2);
        tmpp--;
        //cout<<i<<' '<<tmpp<<endl;
        anss+=tmpp;
        ans-=2*tmpp;
    }
    cout<<anss<<' '<<ans;
    cout.flush();
    //system("pause");
    return 0;
}