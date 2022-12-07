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
int a[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int dis=y-x;
        int pos=lower_bound(a+1,a+n+1,dis)-a;
        int posd=pos-1;
        int ans=0;
        if(pos<=n){
            if(y>a[pos]&&abs(y-a[pos]-x)<dis){
                dis=abs(y-a[pos]-x);
                ans=pos;
            }
        }
        if(y>a[posd]&&abs(y-a[posd]-x)<=dis){
            ans=posd;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}