#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int f[N];
int a[N];
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
        memset(f,0,sizeof(f));
        int ans=0;
        int exc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(i+a[i]>n)ans=max(ans,f[i]+a[i]);
            else {
                f[i+a[i]]=max(f[i+a[i]],f[i]+a[i]);
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
}