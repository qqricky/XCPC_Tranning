#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[N];
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
        int x,y;
        cin>>x>>y;
        int m=y-x;
        int n;
        cin>>n;
        int p,w;
        memset(f,0x3f,sizeof(f));
        f[0]=0;
        for(int i=1;i<=n;i++){
            cin>>p>>w;
            for(int j=w;j<=m;j++){
                f[j]=min(f[j],f[j-w]+p);
            }
        }
        if(f[m]==0x3f3f3f3f)cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<f[m]<<'.'<<endl;
    }
    //system("pause");
    return 0;
}