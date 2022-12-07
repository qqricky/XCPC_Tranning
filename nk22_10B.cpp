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
vector<int>mp[N];
int sz[N]={};
int cnt2[N]={};
int cnt5[N]={};
int f[N]={};
int g[N]={};
int pa[N]={};
set<int>s1,s2;
void dfs(int now,int fa){
    sz[now]=1;
    pa[now]=fa;
    int val=now;
    while(val%2==0){
        val/=2;
        cnt2[now]++;
    }
    val=now;
    while(val%5==0){
        val/=5;
        cnt5[now]++;
    }
    for(int x:mp[now]){
        if(x==fa)continue;
        dfs(x,now);
        sz[now]+=sz[x];
    }
}
void calc(int now,int fa){
    f[now]=(sz[pa[now]]-sz[now])*cnt2[pa[now]];
    f[now]+=f[pa[now]];
    g[now]=(sz[pa[now]]-sz[now])*cnt5[pa[now]];
    g[now]+=g[pa[now]];
    for(int x:mp[now]){
        if(x==fa)continue;
        calc(x,now);
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs(1,0);
    calc(1,0);
    while(q--){
        int x;
        cin>>x;
        int ans2=f[x];
        int ans5=g[x];
        ans2+=sz[x]*cnt2[x];
        ans5+=sz[x]*cnt5[x];
        // cout<<ans2<<' '<<ans5<<'\n';
        cout<<min(ans2,ans5)<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}