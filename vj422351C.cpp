#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
const int N=1e3+10; 
using namespace std;
int v[N];
int w[N];
int f[N][N];
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
        int n,m;
        cin>>n>>m;
        int W;
        for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
        cin>>W;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=W;j>=w[i];j--){
                for(int k=1;k<=m;k++){
                    f[k][j]=max(f[k][j],f[k-1][j-w[i]]+v[i]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=W;i++)ans=max(ans,f[m][i]);
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}