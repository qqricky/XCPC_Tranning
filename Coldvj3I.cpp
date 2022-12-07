#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll c[505][505];
double dp[505][505]={};
void C_(int n)
{
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=n;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
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
    int n,m;
    cin>>n>>m;
    double ans=0;
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++){
            if(j==n){
                dp[i+1][j]+=dp[i][j]*0.5;
                dp[i+1][j-1]+=dp[i][j]*0.5;
            }
            else {
                dp[i+1][j]+=dp[i][j]*0.5;
                dp[i+1][j+1]+=dp[i][j]*0.5;
            }
        }
    }
    for(int i=1;i<=min(n,m);i++){
        ans+=dp[m][i]*i;
    }
    cout<<fixed<<setprecision(7)<<ans;
    //system("pause");
    return 0;
}