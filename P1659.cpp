#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*f;
}
const ll mod=19930726;
string str;
ll n,k;
ll len,len2;
char s[2*N];
ll p[2*N];
ll ans[N]={};
ll tot;
ll pow_Q(ll a,ll b){
    ll ans=1,base=a;
    while(b){
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
void init()
{
    s[0]='#';
    s[1]='#';
    for(int i=1; i<=len; i++)
    {
        s[i*2]=str[i];
        s[i*2+1]='#';
    }
    len2=len*2+1;
}
void manacher()
{
    ll mid=0,mr=0;
    for(int i=1; i<=len2; i++)
    {
        if(mr>i)
            p[i]=min(p[2*mid-i],mr-i);
        else
            p[i]=1;
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]+i>mr)
        {
            mr=p[i]+i;
            mid=i;
        }
        if(i%2==0){
            ans[1]++;
            ans[p[i]]--;
        }
    }
}
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>len>>k;
    cin>>str;
    n=len;
    len=str.length();
    str=' '+str;
    tot=1;
    init();
    manacher();
    for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
    int now=n;
    if(n%2==0)now--;
    while(k&&now>=1){
        if(ans[now]<=k){
            tot=(tot*pow_Q(now,ans[now]))%mod;
            k-=ans[now];
        }
        else{
            tot=(tot*pow_Q(now,k))%mod;
            k=0;
        }
        now-=2;
    }
    cout<<tot;
    //system("pause");
    return 0;
}