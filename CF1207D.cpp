#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll fac[N]={};
const ll mod=998244353;
void init(){
    fac[0]=1;
    for(int i=1;i<=3e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
struct node
{
    int x,y;
    bool operator=(const node& a)const{
        return a.x==x&&y==a.y;
    }
}nd[N];
bool cmp1(node a,node b){
    return a.x<b.x;
}
bool cmp2(node a,node b){
    return a.y<b.y;
}
bool cmp3(node a,node b){
    return (a.x<b.x||(a.x==b.x&&a.y<b.y));
}
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nd[i].x>>nd[i].y;
    }
    ll ans=1;
    int cnt=0;
    sort(nd+1,nd+n+1,cmp1);
    for(int i=1;i<=n;i++){
        if(nd[i].x!=nd[i-1].x){
            ans=(ans*fac[cnt])%mod;
            cnt=1;
        }
    }
    ans=(ans*fac[cnt])%mod;
    cnt=0;
    sort(nd+1,nd+n+1,cmp2);
    for(int i=1;i<=n;i++){
        if(nd[i].y!=nd[i-1].y){
            ans=(ans*fac[cnt])%mod;
            cnt=1;
        }
    }
    sort(nd+1,nd+n+1,cmp3);
    bool flag=1;
    ll tmp=1;
    for(int i=2;i<=n;i++){
        
    }
    ans=(ans*fac[cnt])%mod;
    cout.flush();
    system("pause");
    return 0;
}