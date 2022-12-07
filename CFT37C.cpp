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
double t,x;
double f(double y){
    double k=(t-y);
    if(y<=1.0*t/6){
        return k*y*(x/(1.0*t/6));
    }
    else if(y<=1.0*t/3){
        return (x+(y-1.0*t/6)*(6.0*(100-x)/t))*k;
    }
    else return 100*k;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>t;
    double x1=t/2;
    double x2=(-8*x+700)/(12.0*(100-x))*t;
    double x3=1.0*t/3;
    double x4=1.0*t/6;
    double ans=0;
    if(x1>=0&&x1<=(1.0*t)/6){
        ans=max(ans,f(x1));
    }
    if(x2>=(1.0*t/6)&&x2<=1.0*t/3){
        ans=max(ans,f(x2));
    }
    ans=max(ans,f(x3));
    ans=max(ans,f(x4));
    cout<<fixed<<setprecision(7)<<ans;
    cout.flush();
    //system("pause");
    return 0;
}