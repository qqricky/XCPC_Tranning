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
const ll mod=1e9+7;
ll f[2070][1070]={};
ll sum[2070]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    f[0][0]=1;
    for(int i=1;i<=2*n;i++){
        for(int j=i/2+i%2;j<=min(i,n);j++){
            f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
            sum[i]=(sum[i]+f[i][j])%mod;
        }
    }
    for(int i=1;i<=2*n;i+=2){
        ans=(ans+sum[i])%mod;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}