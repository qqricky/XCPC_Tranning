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
ll a[N];
ll f[N];
int fa[N];
unordered_map<int,int>g[N];
int getfa(int x){
    return x==fa[x] ? x : fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x==y)return;
    if(x>y){
        fa[x]=y;
    }else{
        fa[y]=x;
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=n;i++){
            f[i]=0;
            g[i].clear();
        }
        ll ans=0;
        for(int i=1;i<=3;i++)f[i]=a[i];
        g[2][3]=g[3][2]=1;
        g[1][3]=g[3][1]=2;
        g[2][1]=g[1][2]=3;
        for(int i=4;i<=n;i++){
            int x,y;
            cin>>x>>y;
            int rt=getfa(g[x][y]);
            // cout<<rt<<endl;
            f[rt]+=a[i];
            merge(i,rt);
            g[i][x]=g[x][i]=y;
            g[i][y]=g[y][i]=x;
        }
        cout<<max(f[1],max(f[2],f[3]))<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}