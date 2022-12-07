#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2070; 
ll mod=1e9+7;
using namespace std;
ll f[N][N]={};
ll ans=0;
void solve(int x)
{

}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        f[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int t=2;t<=k;t++){
                for(int j=1;j*j<=i;j++){
                    if(i%j==0){
                        if(j*j==i){
                            f[i][t]=(f[j][t-1]+f[i][t])%mod;
                        }
                        else{
                            f[i][t]=(f[j][t-1]+f[i][t])%mod;
                            f[i][t]=(f[i/j][t-1]+f[i][t])%mod;
                        }
                    }
                }
        }
        ans=(ans+f[i][k])%mod;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}