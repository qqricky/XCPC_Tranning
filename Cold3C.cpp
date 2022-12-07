#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[105][105];
int f[105][105];
int mp[105][105];
int n,m;
void put(int pos,int x)
{
    if(pos>n)return;
    if(pos!=n)
    cout<<x<<' ';
    else cout<<x<<endl;
    put(pos+1,mp[pos][x]);
}
int putt(int pos,int x)
{
    if(pos==1)return x;
    return putt(pos-1,mp[pos][x]);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>m>>n)
    {
        memset(f,0,sizeof(f));
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>a[j][i];
            }
        }
        if(m==1){
            int sum=0;
            for(int i=1;i<=n;i++)sum+=a[i][1];
            for(int i=1;i<=n-1;i++)cout<<1<<' ';
            cout<<1<<"\n";
            cout<<sum<<"\n";
            continue;
        }
        for(int j=1;j<=m;j++)f[n][j]=a[n][j];
        for(int i=n-1;i>=1;i--){
            for(int j=2;j<=m-1;j++){
                f[i][j]=min(f[i+1][j],min(f[i+1][j-1],f[i+1][j+1]))+a[i][j];
                int minn=0x3f3f3f3f;
                for(int k=j-1;k<=j+1;k++){
                    if(f[i+1][k]<minn){mp[i][j]=k;minn=f[i+1][k];}
                }
            }
            f[i][1]=min(f[i+1][1],min(f[i+1][m],f[i+1][1+1]))+a[i][1];
            f[i][m]=min(f[i+1][1],min(f[i+1][m],f[i+1][m-1]))+a[i][m];
            int minn=f[i+1][m];
            mp[i][1]=m;
            for(int k=2;k>=1;k--){
                if(f[i+1][k]<=minn){
                    minn=f[i+1][k];
                    mp[i][1]=k;
                }
            }
            minn=f[i+1][1];
            mp[i][m]=1;
            for(int k=m-1;k<=m;k++){
                if(f[i+1][k]<minn){
                    minn=f[i+1][k];
                    mp[i][m]=k;
                }
            }
        }
        int ans=0x3f3f3f3f;
        int pos=0;
        for(int j=1;j<=m;j++){
            if(f[1][j]<ans){
                ans=f[1][j];
                pos=j;
            }
        }
        put(1,pos);
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}