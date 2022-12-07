#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=4e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        ll ans=0;
        a[0]=0;
        a[n+1]=0;
        for(int i=1;i<=n;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]){
                ans+=a[i]-max(a[i-1],a[i+1]);
                a[i]=max(a[i-1],a[i+1]);
            }
        }
        for(int i=1;i<=n+1;i++){
            ans+=abs(a[i]-a[i-1]);
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}