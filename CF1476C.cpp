#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
int c[N],a[N],b[N];
ll f[N];
using namespace std;
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
        for(int i=1;i<=n;i++)cin>>c[i];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        ll ans=0;
        f[2]=c[2]+abs(a[2]-b[2])+1;
        ans=max(ans,f[2]);
        for(int i=3;i<=n;i++){
            if(b[i]==a[i]){
                f[i]=c[i]+1;
                ans=max(ans,f[i]);
            }
            else{
                f[i]=max((ll)c[i]+abs(a[i]-b[i])+1,(ll)f[i-1]+c[i]-abs(b[i]-a[i])+1);
                ans=max(ans,f[i]);
            }
        }
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}