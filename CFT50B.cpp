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
const double pi=acos(-1);
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
        int a,b,r,dd;
        cin>>a>>b>>r>>dd;
        double d=1.0*dd/180.0*pi;
        double alp=atan(1.0*b/(a+r));
        if(d>=alp){
            double ans=sqrt(1.0*(a+r)*(a+r)+1.0*b*b)-r;
            cout<<fixed<<setprecision(8)<<ans<<'\n';
            continue;
        }
        double thi=pi/2-d*1.0;
        double ans=(1.0*b-tan(d)*(1.0*a+r))*cos(thi)+(1.0*a+r)/cos(d)-r;
        cout<<fixed<<setprecision(8)<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}