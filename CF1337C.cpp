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
vector<int>mp[N];
struct node
{
    ll d,v;
}nd[N];
bool cmp(node a,node b)
{
    return (a.d-a.v)>(b.d-b.v);
}
void dfs(int now,int fa)
{
    for(int j=0;j<mp[now].size();j++){
        if(mp[now][j]==fa)continue;
        nd[mp[now][j]].d=nd[now].d+1;
        dfs(mp[now][j],now);
        nd[now].v+=nd[mp[now][j]].v+1;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    nd[0].d=nd[1].d=0;
    dfs(1,0);
    sort(nd+1,nd+n+1,cmp);
    ll ans=0;
    for(int i=1;i<=k;i++)ans+=(nd[i].d-nd[i].v);
    cout<<ans<<endl;
    cout.flush();
    //system("pause");
    return 0;
}