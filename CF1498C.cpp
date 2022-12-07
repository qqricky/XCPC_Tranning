#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
const ll mod=1e9+7;
ll f[1070][1070][2];
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
        int n,k;
        cin>>n>>k;
        
        for(int i=0;i<=n+1;i++){
            f[1][i][0]=0;
            f[1][i][1]=0;
        }
        for(int i=2;i<=k;i++){
            ll tot=0;
            //f[i][n][0]=1;
            for(int j=n-1;j>=1;j--){
                f[i][j][0]=(f[i-1][j+1][1]+1)%mod;
                if(i>2){
                    f[i][j][0]=(f[i][j][0]+tot)%mod;
                    tot=(tot+f[i-1][j+1][1])%mod;
                }
            }
            tot=0;
            f[i][1][1]=1;
            for(int j=2;j<=n;j++){
                f[i][j][1]=(f[i-1][j-1][0]+1)%mod;
                if(i>2){
                    f[i][j][1]=(f[i][j][1]+tot)%mod;
                    tot=(tot+f[i-1][j-1][0])%mod;
                }
            }
        }
        ll sum=1;
        //for(int i=1;i<=n;i++)cout<<f[2][i][0]<<endl;
        for(int i=1;i<=n;i++)sum=(sum+f[k][i][1])%mod;
        cout<<sum<<"\n";
    }
    //system("pause");
    return 0;
}