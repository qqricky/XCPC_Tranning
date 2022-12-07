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
vector<int>v[N];
int f[N];
ll ans;
void dfs(int now,int fa){
    if(v[now].size()==1&&now!=1){
        f[now]=1;
        return;
    }
    int cnt=0;
    for(int i=0;i<v[now].size();i++){
        if(v[now][i]==fa)continue;
        dfs(v[now][i],now);
        cnt+=f[v[now][i]];
    }
    if(cnt==0)f[now]=1;
    else{
        f[now]=0;
        ans+=cnt-1;
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
    while(t--)
    {
        int n;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,-1);
        cout<<ans+1<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}