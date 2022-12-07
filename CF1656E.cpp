#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
int du[N];
int p[N];
void dfs(int now,int fa,int sig){
    p[now]=du[now]*sig;
    for(int u:mp[now]){
        if(u==fa)continue;
        dfs(u,now,-sig);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(du,0,sizeof(du[0])*(n+1));
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
            du[x]++;
            du[y]++;
        }
        dfs(1,0,1);
        for(int i=1;i<=n;i++)cout<<p[i]<<' ';
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}