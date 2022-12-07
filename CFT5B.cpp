#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[N][6][2];//0-  1+
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++){cin>>a[i];if(a[i]==0)flag=1;}
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            f[i][1][1]=f[i-1][1][1];
            f[i][1][0]=f[i-1][1][0];
            if(a[i]>0)f[i][1][1]=max(f[i][1][1],a[i]);
            if(a[i]<0)f[i][1][0]=max(f[i][1][0],a[i]);
            for(int j=2;j<=5;j++){
                if(a[i]>=0){
                    if(f[i-1][j-1][1]!=0&&f[i-1][j][1]!=0)
                    f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][1]*a[i]);
                    else if(f[i-1][j-1][1]!=0){
                        f[i][j][1]=f[i-1][j-1][1]*a[i];
                    }
                    else if(f[i-1][j][1]!=0)
                        f[i][j][1]=f[i-1][j][1];
                    if(f[i-1][j-1][0]!=0&&f[i-1][j][0]!=0)
                    f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][0]*a[i]);
                    else if((f[i-1][j-1][0]!=0)){
                        f[i][j][0]=f[i-1][j-1][0]*a[i];
                    }
                    else if(f[i-1][j][0]!=0)
                        f[i][j][0]=f[i-1][j][0];
                }
                else{
                    if(f[i-1][j-1][0]!=0&&f[i-1][j][1]!=0)
                    f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]*a[i]);
                    else if(f[i-1][j-1][0]!=0){
                        f[i][j][1]=f[i-1][j-1][0]*a[i];
                    }
                    else if(f[i-1][j][1]!=0)
                        f[i][j][1]=f[i-1][j][1];
                    if(f[i-1][j-1][1]!=0&&f[i-1][j][0]!=0)
                    f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][1]*a[i]);
                    else if(f[i-1][j-1][1]!=0){
                         f[i][j][0]=f[i-1][j-1][1]*a[i];
                    }
                    else if(f[i-1][j][0]!=0)
                        f[i][j][0]=f[i-1][j][0];
                }
            }
        }
        for(int i=1;i<=n;i++)
        std::cout<<"qqq"<<f[i][1][1]<<endl;
        int ans=-INF;
        for(int i=1;i<=n;i++){
            if(f[i][5][0]!=0)
            ans=max(ans,f[i][5][0]);
            if(f[i][5][1]!=0)
            ans=max(ans,f[i][5][1]);
        }
        if(flag)ans=max(0,ans);
        std::cout<<ans<<endl;
    }
    system("pause");
    return 0;
}