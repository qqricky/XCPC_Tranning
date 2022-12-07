#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
const ll mod=1e9+7;
ll f1[12][1070];
ll f2[12][1070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f1[1][i]=f2[1][i]=1;
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=j;k++){
                f1[i][j]=(f1[i][j]+f1[i-1][k])%mod;
            }
            for(int k=j;k<=n;k++){
                f2[i][j]=(f2[i][j]+f2[i-1][k])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        f1[m][i]=(f1[m][i-1]+f1[m][i])%mod;
    }
    for(int i=n;i>=1;i--){
        ans=(ans+f2[m][i]*f1[m][i]%mod)%mod;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}