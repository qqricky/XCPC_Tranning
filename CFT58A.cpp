#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
ull k1,k2;
ull xorShift128Plus(){
    ull k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
int n,m,u[N],v[N];
ull w[N];
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
const ull mod=1e9+7;
int f[N];
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
int merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x<y)f[x]=y;
    else f[y]=x;
}
struct edge
{
    int x,y;
    ull w;
}ed[N];
bool cmp(edge a,edge b){
    return a.w<b.w;
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
        cin>>n>>m>>k1>>k2;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=m;i++){
            ull u,v,w;
            u=xorShift128Plus()%n+1;
            v=xorShift128Plus()%n+1;
            ed[i].x=u;
            ed[i].y=v;
            w=xorShift128Plus();
            ed[i].w=w;
        }
        sort(ed+1,ed+m+1,cmp);
        set<int>s;
        ull ans=0;
        for(int i=1;i<=m;i++){
            int x=getfa(ed[i].x);
            int y=getfa(ed[i].y);
            if(x!=y){
                ans=(ans+ed[i].w)%mod;
                merge(x,y);
            }
        }
        for(int i=1;i<=n;i++){
            s.insert(getfa(i));
        }
        if(s.size()>1)cout<<0<<'\n';
        else cout<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}