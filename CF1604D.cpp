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
        ll x,y;
        cin>>x>>y;
        ll n;
        if(x==y){
            cout<<x<<'\n';
            n=x;
        }
        else if(x>y){
            cout<<x+y<<'\n';
            n=x+y;
        }
        else{
            ll tmp=y/x;
            n=y-(y-tmp*x)/2;
            cout<<y-(y-tmp*x)/2<<'\n';
        }
        //cout<<(n%x==y%n ? "Can" : "can't" )<<endl;
    }
    cout.flush();
    //system("pause");
    return 0;
}