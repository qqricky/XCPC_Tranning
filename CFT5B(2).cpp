#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll f[N][6][2];//0-  1+
ll a[N];
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
        int n;
        cin>>n;
        int flag=1;
        int ff=1;
        int cnt=0;
        int cnt2=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=0)cnt++;
            else cnt2++;
            if(a[i]==0)ff=0;
            if(a[i]>0){flag=0;}
        }
        if((flag&&ff)){
            sort(a+1,a+n+1);
                ll cnt=1;
                for(int i=n;i>=n-4;i--)cnt*=a[i];
                cout<<cnt<<"\n";
            continue;
        }
        else if(flag){
            cout<<0<<"\n";
            continue;
        }
        else if((cnt==2&&cnt2==3)||(cnt==4&&cnt2==1)){
            if(ff=0){
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                if(a[i]>0)a[i]=-a[i];
            }
            ll sum=1;
                sort(a+1,a+n+1);
                for(int i=n;i>=n-4;i--)sum*=a[i];
                cout<<sum<<endl;
                continue;
        }
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=5;j++){
                f[i][j][1]=0;
                f[i][j][0]=0;
            }
        }
        f[0][0][0]=1;
        f[0][0][1]=1;
        for(int i=1;i<=n;i++){
            f[i][0][0]=1;
            f[i][0][1]=1;
            for(int j=1;j<=5;j++){
                if(a[i]==0){
                    f[i][j][1]=f[i-1][j][1];
                    f[i][j][0]=f[i-1][j][0];
                }
                else if(a[i]>0){
                    f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][1]*a[i]);
                    f[i][j][0]=min(f[i-1][j][0],f[i-1][j-1][0]*a[i]);
                }
                else{
                    f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]*a[i]);
                    f[i][j][0]=min(f[i-1][j][0],f[i-1][j-1][1]*a[i]);
                }
            }
        }
        cout<<f[n][5][1]<<"\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}