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
int a[N];
ll sum[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    ll res=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[n+1]=0;
    for(int i=n;i>=1;i--){
        sum[i]=sum[i+1]+a[i];
    }
    ll tot=sum[1];
    bool vis=0;
    sort(sum+1,sum+n+1,greater<ll>());
    for(int i=1;i<=k;i++){
        if(sum[i]==tot)vis=1;
        res+=sum[i];
    }
    if(!vis){
        res-=sum[k];
        res+=tot;
    }
    cout<<res<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}