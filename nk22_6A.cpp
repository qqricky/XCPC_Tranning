#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
set<ll>f[3];
set<ll>v;
ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,x;
        cin>>a>>b>>c>>x;
        ll val=gcd(a,b);
        val=gcd(val,c);
        if(x==0){
            cout<<"Yes\n";
            continue;
        }
        if(val%x==0)cout<<"Yes\n";
        else cout<<"No\n";
    }
    // cout.flush();
    // system("pause");
    return 0;
}