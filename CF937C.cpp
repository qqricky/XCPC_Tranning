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
    ll k,d,t;
    cin>>k>>d>>t;
    t*=2;
    ll t1=k;
    ll t2=d-k%d;
    if(k%d==0)t2=0;
    ll tt=t/(t1*2+t2);
    ll ans=tt*(t1*2+t2*2);
    t-=tt*(t1*2+t2);
    if(t>=t1*2){
        ans+=t1*2;
        t-=t1*2;
        ans+=t*2;
    }
    else{
        ans+=t;
    }
    if(ans&1){
        cout<<ans/2<<".5";
    }
    else{
        cout<<ans/2<<".0";
    }
    cout.flush();
    //system("pause");
    return 0;
}