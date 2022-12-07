#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
struct edge
{
    int x,y;
    int w;
}eg[2*N];
int tot;
vector<int>inv[N];
int ot[N];
int ans;
bool vis[N];
string str;
void dfs(int now)
{
    
}
void go(int now)
{
    queue<int>q;
    q.push(now);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<inv[u].size();i++){
            int tt=inv[u][i];
            if(eg[tt].y==u)continue;
            q.push(eg[tt].y);
            if(vis[u]==2&&eg[tt].w==1){
                vis[eg[tt].y]=2;
                ans++;
            }
            else{
                vis[eg[tt].y]=1;
            }
        }
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
        memset(vis,0,sizeof(bool)*(n+1));
        tot=0;
        for(int i=1;i<=n;i++)inv[i].clear();
        ans=0;
        int y;
        vector<int>tmp;
        for(int i=1;i<=n;i++){
            cin>>y>>str;
            if(y==i){
                vis[i]=2;
                if(str=="werewolf"){
                    ans++;
                    go(i);
                }
                continue;
            }
            eg[++tot].x=i;
            ot[i]=tot;
            eg[tot].y=y;
            eg[++tot].x=y;
            eg[tot].y=i;
            inv[y].push_back(tot);
            if(str=="werewolf"){
                eg[tot].w=1;
                eg[tot-1].w=1;
            }
            else{
                eg[tot].w=0;
                eg[tot-1].w=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            int val=ot[i];
            if(vis[val]){
                vis[i]=1;
                continue;
            }
            
        }
    }
    //system("pause");
    return 0;
}