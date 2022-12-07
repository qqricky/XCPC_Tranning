#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
int a[N];
int b[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    ll c;
    while(t--)
    {
        ll ans=INF;
        ll c;
        int n;
        cin>>n>>c;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)cin>>b[i];
        b[n]=INF;
        ll cnt=0;
        ll now=0;
        for(int i=1;i<=n;i++){
            if(i>1)cnt++;
            if(cnt>ans)break;
            ans=min(ans,cnt+(ll)(c-now)/a[i]+(ll)(((c-now)%a[i])!=0));
            //cout<<ans<<endl;
            //cout<<cnt<<endl;
            if(now>=b[i]){
                now-=b[i];
                continue;
            }
            cnt+=((b[i]-now)/a[i]+(((b[i]-now)%a[i])!=0));
            if((b[i]-now)%a[i]==0)now=0;
            else now=a[i]-(b[i]-now)%a[i];
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}