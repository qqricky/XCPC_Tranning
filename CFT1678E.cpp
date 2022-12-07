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
bool vis[N];
int a[N];
set<int>mp[N];
bool dfs(int x,int num,int fa){
    vis[x]=1;
    // cout<<x<<' ';
    for(int v:mp[x]){
        if(v==fa)continue;
        if(vis[v]){
            // cout<<"sdafjklsd "<<num<<'\n'
            return num&1;
        }
        else{
            return dfs(v,num+1,x);
        }
    }
    return 0;
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
        int cnt=0;
        memset(vis,0,sizeof(bool)*(n+5));
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a[x]=i;
            mp[i].clear();
        }
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            int y=a[x];
            x=i;
            if(x==y){
                vis[x]=1;
                cnt++;
                continue;
            }
            mp[x].insert(y);
            mp[y].insert(x);
            // cout<<x<<' '<<y<<'\n';
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt+=dfs(i,1,*mp[i].begin());
            }
        }
        ll ans=0;
        ll l=1,r=n;
        while(r-l-1>=cnt){
            ans+=2*(r-l);
            l++,r--;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}