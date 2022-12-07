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
struct node{
    int x,y;
}nd[N];
bool cmp(node &a,node &b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}
const ll mod=1e9+7;
ll powq(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a%mod);
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll fac[2*N];
ll ifac[2*N];
void init(){
    fac[0]=1;
    for(int i=1;i<=2e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    ifac[200000]=powq(fac[200000],mod-2);
    for(int i=2e5-1;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}
ll c(int n,int m){
    if(n<m||m<0)return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll f[2070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    init();
    for(int i=1;i<=n;i++){
        cin>>nd[i].x>>nd[i].y;
    }
    sort(nd+1,nd+n+1,cmp);
    nd[n+1].x=h,nd[n+1].y=w;
    for(int i=1;i<=n+1;i++){
        f[i]=c(nd[i].x+nd[i].y-2,nd[i].x-1);
        for(int j=1;j<i;j++){
            if(nd[j].y<=nd[i].y){
                int dx=nd[i].x-nd[j].x;
                int dy=nd[i].y-nd[j].y;
                f[i]=((f[i]-f[j]*c(dx+dy,dx))%mod+mod)%mod;
            }
        }
    }
    cout<<f[n+1]%mod;
    cout.flush();
    //system("pause");
    return 0;
}