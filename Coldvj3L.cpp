#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[5010][2510][3];
int a[5010];
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    k=ceil((double)n/2);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=0;
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
        f[i][0][0]=0;
        for(int j=1;j<=k;j++){
            if(a[i]<=a[i-1]){
                f[i][j][1]=f[i-1][j-1][0]+a[i]-a[i-1]+1;
                f[i][j][0]=min(f[i-1][j][1],f[i-1][j][0]);
            }
            else {
                f[i][j][1]=f[i-1][j-1][0];
                f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]+a[i]-a[i-1]+1);
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout<<min(f[n][i][1],f[n][i][0])<<' ';
    }
    //system("pause");
    return 0;
}