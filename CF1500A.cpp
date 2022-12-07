#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[233];
int b[233];
int tt[233];
int c[233];
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
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
        for(int i=1;i<=n;i++)cin>>tt[i];
        int ans=0;
        int cnt=0;
        int cur=0;
        b[0]=0;
        for(int i=1;i<=n;i++){
            cur+=a[i]-b[i-1]+tt[i];
            int tmp=ceil((double)((double)b[i]-a[i])/2);
            if(i==n)ans=cur;
            cur=max(b[i],cur+tmp);
            //cout<<i<<'Q'<<cur<<endl;
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}