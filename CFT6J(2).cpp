#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int f[120][120][2];
int cnt[120];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[150];
    int n;
    cin>>n;
    int od=(n+1)/2;
    int ev=n/2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1){od--;a[i]=1;}
        else if(a[i]==0){a[i]=-1;}
        else {ev--;a[i]=0;}
    }
    memset(f,0x3f,sizeof(f));
    cnt[0]=0;
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+(a[i]==-1);
    }
    f[0][0][0]=0;
    f[0][0][1]=0;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            for(int k=0;k<=1;k++){
                f[i][0][0]=min(f[i][0][0],f[i-1][0][k]+(k!=0));
                for(int j=1;j<=min(od,cnt[i]);j++){
                    f[i][j][1]=min(f[i][j][1],f[i-1][j-1][k]+(k!=1));
                    f[i][j][0]=min(f[i][j][0],f[i-1][j][k]+(k!=0));
                }
            }
        }
        else{
            for(int j=0;j<=min(od,cnt[i]);j++){
                for(int k=0;k<=1;k++){
                    f[i][j][a[i]]=min(f[i][j][a[i]],f[i-1][j][k]+(a[i]!=k));
                }
            }
        }
    }
    cout<<min(f[n][od][1],f[n][od][0])<<endl;
    //system("pause");
    return 0;
}