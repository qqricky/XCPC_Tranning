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
ll a[N];
ll b[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s,t,h;
        cin>>n>>s>>t>>h;
        for(int i=1;i<n;i++)cin>>a[i];
        for(int i=1;i<n;i++)cin>>b[i];
        sort(a+1,a+n);
        sort(b+1,b+n);
        ll sum1=0,sum2=0;
        for(int i=s+1;i<n-t;i++){
            sum1+=a[i];
            sum2+=b[i];
        }
        ll x=a[s];
        ll y=a[n-t];
        ll xx=b[s];
        ll yy=b[n-t];
        if(sum1+y-(sum2+xx)<=0){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        ll sum=sum1-sum2;
        ll ans=INF;
        if(sum<=0){
            cout<<-sum+1<<'\n';
            continue;
        }
        if(sum+x-yy>0){
            ans=min(ans,1-h);
        }
        else if(sum+y-yy>0){
            ans=min(ans,1+yy-sum-h);
        }
        if(sum+x-xx>0){
            ans=min(ans,1-(x-1+sum));
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}