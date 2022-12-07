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
int a[N];
int b[N];
int f[N][2]={};
int g[N][2]={};
int h[N][2]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[b[i]]=i;
    }
    for(int i=n;i>=1;i--){
        f[a[i]][1]=f[a[i]+1][1]+1;
        f[a[i]][0]=f[a[i]-1][0]+1;
    }
    for(int i=1;i<=n;i++){
        g[a[i]][1]=g[a[i]-1][1]+1;
        g[a[i]][0]=g[a[i]+1][0]+1;
        h[a[i]][1]=h[a[i]-1][1]+1;
        h[a[i]][0]=h[a[i]+1][0]+1;
    }
    for(int i=n;i>=0;i--){
        f[i][1]=max(f[i][1],f[i+1][1]);
        h[i][0]=max(h[i][0],h[i+1][0]);
    }
    for(int i=1;i<=n;i++){
        h[i][1]=max(h[i][1],h[i-1][1]);
        f[i][0]=max(f[i][0],f[i-1][0]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=max(g[a[i]][0],g[a[i]][1]);
        int y=min(g[a[i]][0],g[a[i]][1]);
        if(x-(x&1)-1>=y-1)continue;
        int mx=max(f[a[i]+1][1],f[a[i]-1][0]);
        mx=max(mx,h[a[i]-1][1]);
        mx=max(mx,h[a[i]+1][0]);
        mx=max(mx,1);
        if(x-1>mx-1){
            // std::cout<<i<<endl;
            // std::cout<<x<<' '<<y<<' '<<mx<<endl;
            ans++;
        }
    }
    std::cout<<ans;
    std::cout.flush();
    // system("pause");
    return 0;
}