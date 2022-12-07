#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int f[620][220];
int a[220];
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
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        f[0][0]=0;
        int ans=INF;
        for(int i=1;i<=2*n;i++){
            f[i][0]=0;
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i-1][j],f[i-1][j-1]+abs(a[j]-i));
            }
            ans=min(ans,f[i][n]);
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}