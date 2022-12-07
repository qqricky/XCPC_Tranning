#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10;
using namespace std;
int f[2][N];
const ll mod=1e9+7;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int x,y;
    for(y=1;y<=100;y++)
    {
        x=3;
        if(x<0)x=-x;
        if(y<0)y=-y;
        memset(f,0,sizeof(f));
        f[x&1][y]=1;
        int cnt=0;
        for(int i=x;i>=0;i--){
            for(int j=y;j>=0;j--){
                int k=x&1;
                f[k][j]=(f[1-k][j]+f[k][j])%mod;
                f[k][j]=(f[k][j+1]+f[k][j])%mod;
                cnt=(cnt+f[k][j])%mod;
            }
        }
        cout<<x<<' '<<y<<'Q';
        cout<<cnt<<"\n";
    }
    cout.flush();
    system("pause");
    return 0;
}