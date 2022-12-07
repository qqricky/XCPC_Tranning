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
        int n,s,p;
        cin>>n>>s>>p;
        int x;
        for(int i=1;i<=s;i++)cin>>x;
        ll ans=0;
        if(s>=p){
            ll a=n-s-1;
            ll b=s-p;
            ll c=p-1;
            ans=3*a*c+3*a+a*(a-1)+3*a*b+2*b*(b-1)+5*b+4*b*c+3*c+c*(c-1);
            ans+=1;
            ans*=2;
            // ans=(n-s-1)*(n-s-2)+2*(s-p)*(s-p-1)+p*(p-1)+3*(n-s-1)*(s-p)+3*(n-s-1)*(p-1);
            // ans+=4*(p-1)*(s-p)+n-s-1+2*(s-p)+p+2*(n-s-1)+3*(s-p);
            // ans*=2;
        }
        else{
            ll a=n-p-1;
            ll b=s;
            ll c=p-s;
            ans=a*(a-1)+3*a+3*a*(b-1)+4*a*c+b*(b-1)+b+3*b*c+2*c+2*c*(c-1);
            ans*=2;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}