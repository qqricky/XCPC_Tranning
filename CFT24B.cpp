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
        ll x;
        cin>>x;
        x*=2;
        bool flag=0;
        for(ll i=2;i*i<=x;i++){
            if(x%i==0){
                if(((x/i)-i)&1){
                    flag=1;
                    break;
                }
            }
        }
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}