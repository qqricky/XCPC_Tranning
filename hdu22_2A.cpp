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
int f[N]={};
int a[10]={0,7,31,365};
void init(){
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int j=1;j<=2;j++){
        for(int i=a[j];i<=5e5;i++){
            f[i]=min(f[i],f[i-a[j]]+1);
        }
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=n/365;
        ll cnt=ans;
        ll res=n%365;
        ans+=f[res];
        for(ll i=1;i<=1000;i++){
            if(n-res-i*365<0){
                break;
            }
            cnt--;
            ans=min(ans,cnt+f[res+365*i]);
        }
        if(ans==INF)ans=-1;
        cout<<ans<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}