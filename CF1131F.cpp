#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int f[N];
vector<int>v[N];
vector<int>mp[N];
bool vis[N]={};
int deg[N]={};
int getfa(int x){
    return x==f[x] ? x :f[x]=getfa(f[x]);
}
void merge(int x,int y){
    int xx=x,yy=y;
    x=getfa(x);
    y=getfa(y);
    if(x>y){
        swap(x,y);
    }
    int u=v[x][v[x].size()-1];
    int uu=v[y][v[y].size()-1];
    mp[u].push_back(uu);
    mp[uu].push_back(u);
    deg[u]++;
    deg[uu]++;
    if(deg[u]==2)v[x].erase(v[x].end()-1);
    if(deg[uu]==2)v[y].erase(v[y].end()-1);
    f[x]=y;
    for(int val:v[x])v[y].push_back(val);
}
void dfs(int now){
    vis[now]=1;
    cout<<now<<' ';
    for(int x:mp[now]){
        if(!vis[x])dfs(x);
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        f[i]=i;
        v[i].push_back(i);
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
    int pos;
    for(pos=1;pos<=n;pos++){
        if(deg[pos]==1)break;
    }
    dfs(pos);
    cout.flush();
    //system("pause");
    return 0;
}