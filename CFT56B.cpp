#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int a[1070][1070];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==-1){
                x=i;
                y=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==x)continue;
        int mi=INF;
        for(int j=1;j<=n;j++){
            mi=min(mi,a[i][j]);
        }
        for(int j=1;j<=n;j++){
            a[i][j]-=mi;
        }
    }
    for(int j=1;j<=n;j++){
        if(j==y)continue;
        int mi=INF;
        for(int i=1;i<=n;i++){
            mi=min(mi,a[i][j]);
        }
        for(int i=1;i<=n;i++){
            a[i][j]-=mi;
        }
    }
    int ans=0;
    if(x-1>=1){
        ans+=a[x-1][y];
    }else{
        ans+=a[x+1][y];
    }
    if(y-1>=1){
        ans+=a[x][y-1];
    }else{
        ans+=a[x][y+1];
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}