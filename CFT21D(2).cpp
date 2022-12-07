#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
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
    ll n,d,m,l;
    cin>>n>>d>>m>>l;
    ll dis=m-l;
    if(d>n*m-dis){
        cout<<d;
        return 0;
    }
    ll k=1;
    bool flag=0;
    while(k<=n){
        ll tmp=(k*m-dis)/d;
        tmp++;
        if(tmp*d<k*m){
            cout<<tmp*d;
            flag=1;
            break;
        }
        k++;
    }
    if(!flag){
        ll tmp=(n*m-dis)/d;
        tmp++;
        cout<<tmp*d;
    }
    cout.flush();
    //system("pause");
    return 0;
}