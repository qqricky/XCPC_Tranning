#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
double f[10002][200]={};
double pb[233][233]={};
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
        for(int j=1;j<=n;j++)cin>>pb[i][j];
    }
    f[0][1]=1.0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[i][k]+=f[i-1][j]*pb[j][k];
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<fixed<<setprecision(4)<<f[m][i]<<"\n";
    //system("pause");
    return 0;
}