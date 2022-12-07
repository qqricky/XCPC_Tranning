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
int num[N];
int dep[N];
void dfs(int now,int fa){
    num[now]=1;
    for(int x:mp[now]){
        if(x==fa)continue;
        dep[x]=dep[now]+1;
        dfs(x,now);
        num[now]+=num[x];
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
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        dep[1]=1;
        dfs(1,0);
        for(int i=1;i<=n;i++){
            cout<<dep[i]<<' '<<n-num[i]+1<<'\n';
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}