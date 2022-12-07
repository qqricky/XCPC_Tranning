#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
ll f[2021][2021];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)f[i][i]=0;
    sort(a+1,a+n+1);
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            f[i][j]=min(f[i+1][j]+a[j]-a[i],f[i][j-1]+a[j]-a[i]);
        }
    }
    cout<<f[1][n]<<endl;
    //system("pause");
    return 0;
}