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
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll k1=n-abs(x1-x2);
        ll k2=m-abs(y1-y2);
        ll ans=0;
        ans+=2*k1*k2;
        ll val2=2*k2-m;
        ll val1=2*k1-n;
        if(val1>=1&&val2>=1){
            ans-=val1*val2;
        }
        cout<<n*m-ans<<endl;
    }
    cout.flush();
    //system("pause");
    return 0;
}