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
int len[11]={};
ll ansv[50]={};
int a[N];
int n;
const ll mod=998244353;
ll pow_q(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
inline int calc(int x){
    int cnt=0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}
void add1(int x,int l,int num){
    int pos=1;
    while(x){
        ansv[pos]=(ansv[pos]+(x%10)*1ll*num%mod)%mod;
        if(l){
            l--;
            pos++;
        }
        pos++;
        x/=10;
    }
}
void add2(int x,int l,int num){
    int pos=2;
    l--;
    while(x){
        ansv[pos]=(ansv[pos]+(x%10)*1ll*num%mod)%mod;
        if(l){
            l--;
            pos++;
        }
        pos++;
        x/=10;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        len[calc(a[i])]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            add1(a[i],j,len[j]);
            add2(a[i],j,len[j]);
            //cout<<a[i]<<' '<<j<<' '<<len[j]<<endl;
        }
    }
    ll ans=0;
    for(int  i=1;i<=30;i++){
        //cout<<ansv[i]<<endl;
        ans=(ans+ansv[i]*pow_q(10,i-1)%mod)%mod;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}