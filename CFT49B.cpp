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
ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l,r,w;
    cin>>l>>r>>w;
    ll d=gcd(w,r);
    ll ww=w;
    w/=d;
    r/=d;
    ll ans=(w-1)*d;
    if(ans>l-ww){
        cout<<"DEADLOCK\n";
    }
    else cout<<"OK\n";
    cout.flush();
    //system("pause");
    return 0;
}