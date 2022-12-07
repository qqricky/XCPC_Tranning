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
ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}
ll Exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = Exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==0&&b==0){
        if(c==0)cout<<"1 1";
        else cout<<-1;
        return 0;
    }
    ll val=gcd(a,b);
    if(c%val){
        cout<<-1;
        return 0;
    }
    ll fac=-c/val;
    ll x,y;
    Exgcd(a,b,x,y);
    cout<<x*fac<<' '<<y*fac;
    cout.flush();
    //system("pause");
    return 0;
}