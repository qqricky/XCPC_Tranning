#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
int b[N];
const ll mod=998244353;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    ll ans=1;
    for(int i=n-1;i>=1;i--){
        a[i]=min(a[i],a[i+1]);
    }
    int r=n;
    int l=n;
    for(int i=m;i>1;i--){
        while(a[r]>b[i])r--;
        while(a[l]>=b[i])l--;
        if(a[l+1]!=b[i]){
            ans=0;
            break;
        }
        ans=(ans*(r-l))%mod;
        r=l;
    }
    if(b[1]!=a[1])ans=0;
    cout<<ans;
    cout.flush();
    // system("pause");
    return 0;
}