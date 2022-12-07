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
const ll mod=19940417;
struct node{
    int x,y;
    bool operator < (const node &b){
        if(x==b.x)return y<b.y;
        return x<b.x;
    }
    bool operator ==(const node &b){
        return (x==b.x&&y==b.y);
    }
}nd[N];
ll pow_Q(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll f[N][2]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ma=0;
    for(int i=1;i<=k;i++){
        cin>>nd[i].x>>nd[i].y;
        ma=max(ma,nd[i].y);
    }
    nd[k+1].x=0,nd[k+1].y=0;
    nd[k+2].x=n,nd[k+2].y=0;
    sort(nd+1,nd+k+3);
    k+=2;
    k=unique(nd+1,nd+k+1)-nd-1;
    f[1][0]=1;
    for(int i=2;i<=k;i++){
        // if(abs(nd[i].y-nd[i-1].y)>abs(nd[i].x-nd[i-1].x)||
        // ((abs(nd[i].y-nd[i-1].y)&1)^((nd[i].x-nd[i-1].x)&1))){
        //     cout<<"0 0";
        //     return 0;
        // }
        int a=nd[i-1].x+nd[i-1].y;
        int b=nd[i].x-nd[i].y;
        int num=(b-a)/2+1;
        if(nd[i].x-nd[i-1].x==abs(nd[i].y-nd[i-1].y)){
            if(nd[i].y>nd[i-1].y){
                f[i][1]=(f[i][1]+f[i-1][1])%mod;
            }
            else{
                f[i][0]=(f[i-1][0]+f[i][0]+f[i-1][1])%mod;
            }
            if(nd[i-1].y==0){
                f[i][1]=(f[i][1]+f[i-1][0])%mod;
            }
            continue;
        }
        if(num>=2)f[i][0]=(f[i][0]+f[i-1][0]*pow_Q(2,num-2)%mod)%mod;
        if(num>=1&&nd[i].y>0)f[i][1]=(f[i][1]+f[i-1][1]*pow_Q(2,num-1)%mod)%mod;
        if(num>=2&&nd[i].y>0)f[i][1]=(f[i][1]+f[i-1][0]*pow_Q(2,num-2)%mod)%mod;
        else if(num==1&&nd[i].y>0)f[i][1]=(f[i][1]+f[i-1][0])%mod;
        if(num>=1)f[i][0]=(f[i][0]+f[i-1][1]*pow_Q(2,num-1)%mod)%mod;
        else f[i][0]=(f[i][0]+f[i-1][1])%mod;
        if(f[i-1][1]>0||nd[i-1].y==0)
            ma=max(ma,max(nd[i].y,nd[i-1].y)+(nd[i].x-nd[i-1].x-abs(nd[i].y-nd[i-1].y))/2);
    } 
    // for(int i=1;i<=k;i++){
    //     cout<<nd[i].x<<" @ down:"<<f[i][0]<<" up:"<<f[i][1]<<endl;
    // }
    cout<<f[k][0]%mod<<' '<<ma<<endl;
    cout.flush();
    //system("pause");
    return 0;
}