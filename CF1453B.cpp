#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
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
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=0;
        ll ma=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<n;i++){
            ans+=abs(a[i]-a[i-1]);
            ma=max(ma,2*(a[i]-max(a[i-1],a[i+1])));
            ma=max(ma,2*(min(a[i-1],a[i+1])-a[i]));
            //cout<<i<<'q'<<ma<<endl;
        }
        ans+=abs(a[n]-a[n-1]);
        ma=max(ma,max(abs(a[2]-a[1]),abs(a[n]-a[n-1])));
        cout<<ans-ma<<endl;
    }
    //system("pause");
    return 0;
}