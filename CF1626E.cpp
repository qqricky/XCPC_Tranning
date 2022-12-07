#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
int col[N]={};
int cnt=0,tot=0;
bool v[N]={};
int num[N]={};
void dfs_down(int now,int fa){
    num[now]=col[now];
    for(int u:mp[now]){
        if(u==fa)continue;
        dfs_down(u,now);
        num[now]+=num[u];
        if(num[u]>1&&v[u]){
            cnt+=1-v[now];
            v[now]=1;
        }
    }
}
void dfs_up(int now,int fa){
    for(int u:mp[now]){
        if(u==fa)continue;
        if(tot-num[u]>1&&v[now]){
            cnt+=1-v[u];
            v[u]=1;
        }
        dfs_up(u,now);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>col[i];
        if(col[i]){v[i]=1;tot++;cnt++;}
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y),mp[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(col[i]){
            for(int u : mp[i]){
                cnt+=1-v[u];
                v[u]=1;
            }
        }
    }
    dfs_down(1,0);
    dfs_up(1,0);
    for(int i=1;i<=n;i++)cout<<v[i]<<' ';
    cout.flush();
    //system("pause");
    return 0;
}