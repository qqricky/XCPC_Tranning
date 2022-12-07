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
ll a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll tans=0;
        cin>>n;
        ll mx=0;
        ll ans=0;
        ll cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        for(int i=1;i<=n;i++){
            ans+=(mx-a[i])/3;
            if((mx-a[i])%3==1){
                cnt1++;
            }
            else if((mx-a[i])%3==2){
                cnt2++;
            }
        }
        ans*=2;
        if(cnt2>=cnt1)ans+=cnt2*2;
        else ans+=cnt1*2-1;
        tans=ans;
        ans=0;
        cnt1=0,cnt2=0;
        mx++;
        for(int i=1;i<=n;i++){
            ans+=(mx-a[i])/3;
            if((mx-a[i])%3==1){
                cnt1++;
            }
            else if((mx-a[i])%3==2){
                cnt2++;
            }
        }
        ans*=2;
        if(cnt2>=cnt1)ans+=cnt2*2;
        else ans+=cnt1*2-1;
        tans=min(tans,ans);
        cout<<tans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}