#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
const ll mod=1e9+7;
ll f[10][N];
void pre_work()
{
    for(int i=0;i<9;i++)f[i][1]=1;
    for(int i=0;i<=9;i++)f[i][0]=1;
    f[9][1]=2;
    for(int i=2;i<=200000;i++){
        f[9][i]=(f[0][i-1]+f[1][i-1])%mod;
        for(int j=0;j<9;j++){
            f[j][i]=f[j+1][i-1];
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    pre_work();
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ll ans=0;
        while(n){
            ans=(ans+f[n%10][m])%mod;
            n/=10;
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}