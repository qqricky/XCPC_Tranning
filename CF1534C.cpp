#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=4e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
ll pow_Q(ll a,ll b)
{
    ll ans=1,base=a;
    while(b)
    {
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
int a[N];
int pos[N];
int b[N];
bool v[N];
int cnt;
ll ans;
inline void chain(int now,int st)
{
    cnt++;
    while(now!=st)
    {
        v[now]=1;
        now=b[now];
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        memset(v,0,sizeof(bool)*(n+1));
        for(int i=1;i<=n;i++){
            read(a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            read(b[i]);
            b[i]=pos[b[i]];
        }
        cnt=0;
        ans=0;
        for(int i=1;i<=n;i++){
            if(v[i])continue;
            v[i]=1;
            chain(b[i],i);
        }
        cout<<pow_Q(2,cnt)<<endl;
    }
    //system("pause");
    return 0;
}