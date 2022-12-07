#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
double dp[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)cin>>dp[i];
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=6;j++){
                dp[i]+=dp[i+j]/(min(6,n-i));
            }
        }
        cout<<"Case "<<k<<": ";
        cout<<fixed<<setprecision(7)<<dp[1]<<endl;
    }
    //system("pause");
    return 0;
}