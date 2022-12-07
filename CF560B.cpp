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
    int x,y;
    int a1,a2,b1,b2;
    cin>>x>>y>>a1>>a2>>b1>>b2;
    bool flag=0;
    if(a1+b1<=x&&b2<=y&&a2<=y)flag=1;
    if(a1+b1<=y&&a2<=x&&b2<=x)flag=1;
    if(a1+b2<=x&&b1<=y&&a2<=y)flag=1;
    if(a1+b2<=y&&b1<=x&&a2<=x)flag=1;
    if(a2+b1<=x&&b2<=y&&a1<=y)flag=1;
    if(a2+b1<=y&&b2<=x&&a1<=x)flag=1;
    if(a2+b2<=x&&b1<=y&&a1<=y)flag=1;
    if(a2+b2<=y&&b1<=x&&a1<=x)flag=1;
    if(flag)cout<<"YES";
    else cout<<"NO";
    cout.flush();
    //system("pause");
    return 0;
}