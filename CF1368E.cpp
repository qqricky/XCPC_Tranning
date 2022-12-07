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
vector<int>imp[N];
bool vis[N]={};
struct node
{
    int in,out;
    int id;
}nd[N];
bool cmp(node x,node y){
    return x.in+x.out<y.in+y.out;
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
        int n,m;
        cin>>n>>m;
        memset(vis,0,sizeof(bool)*(n+2));
        for(int i=1;i<=n;i++){
            mp[i].clear();
            imp[i].clear();
            nd[i].in=nd[i].out=0;
            nd[i].id=i;
        }
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            imp[y].push_back(x);
            nd[x].out++;
            nd[y].in++;
        }
        sort(nd+1,nd+n+1,cmp);
        vector<int>ans;
        for(int i=1;i<=n;i++){
            if(vis[nd[i].id])continue;
            vis[nd[i].id]=1;
            ans.push_back(nd[i].id);
            
        }
    }
    cout.flush();
    system("pause");
    return 0;
}