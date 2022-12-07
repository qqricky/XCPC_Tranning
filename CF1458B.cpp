#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int f[2][102][10002]={};
int a[102],b[102];
int main()
{
    //  freopen("TestCase.in","r",stdin);
    //  freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){cin>>a[i]>>b[i];sum+=b[i];}
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=0;j--){
            for(int k=1;k<=i;k++){
                f[i&1][k][j]=f[!(i&1)][k][j];
                if(j>=b[i])
                {
                    if(f[!(i&1)][k-1][j-b[i]]>0)
                    f[i&1][k][j]=max(f[i&1][k][j],f[!(i&1)][k-1][j-b[i]]+a[i]);
                    if(j==b[i])f[i&1][k][j]=max(f[!(i&1)][k][j],f[!(i&1)][k-1][0]+a[i]);
                    //cout<<i<<j<<k<<"i j  k"<<f[i&1][k][j]<<endl;
                }
            }
        }
    }
    double ans;
    for(int i=1;i<=n;i++){
        ans=0.0;
        for(int j=sum;j>=0;j--){
            if(f[n&1][i][j]>0){
                ans=max(ans,min((double)f[n&1][i][j],j+(double)(sum-j)/2));
                // cout<<"sum-j/"<<(double)(sum-j)/2<<endl;
                // cout<<f[n&1][i][j]<<endl;
                // cout<<ans<<endl;
            }
        }
        cout<<fixed<<setprecision(10)<<ans<<' ';
    }
    //system("pause");
}