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
    ll n,m,q;
    cin>>n>>m>>q;
    ll d=gcd(n,m);
    n/=d,m/=d;
    while(q--){
        ll s1,x1,s2,x2;
        cin>>s1>>x1>>s2>>x2;
        ll y1,y2;
        if(s1==1){
            y1=x1/n+(x1%n>0);
        }
        else{
            y1=x1/m+(x1%m>0);
        }
        if(s2==1){
            y2=x2/n+(x2%n>0);
        }
        else{
            y2=x2/m+(x2%m>0);
        }
        if(y1==y2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}