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
    ll k=1;
    bool flag=0;
    while(k<=n){
        if(k*m/d!=(k*m-dis)/d){
            if(k*m%d==0&&(k*m-dis)/d+1==k*m/d){
                k++;
                continue;
            }
            cout<<((k*m-dis)/d+1)*d;
            flag=1;
            break;
        }
        k++;
        //if(k>=1e5)cout<<k<<endl;
        // ll tm=k*d/m+(k*d%m != 0);
        // if(k*d>tm*m-dis&&k*d<tm*m){
        //     cout<<k*d;
        //     break;
        // }
        // k++;
    }
    if(!flag){
        int tmp=n*m/d;
        tmp++;
        cout<<tmp*d;
    }
    cout.flush();
    //system("pause");
    return 0;
}