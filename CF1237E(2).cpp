#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll f[N];
const ll mod=998244353;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    set<int>s;
    int x=1;
    while(x<=n){
        if(x&1){
            s.insert(x);
            s.insert(x+1);
            x=x*2+2;
            
        }else{
            s.insert(x+1);
            s.insert(x);
            x=x*2+1;
        }
    }
    if(s.count(n))cout<<1;
    else cout<<0;
    cout.flush();
    // system("pause");
    return 0;
}