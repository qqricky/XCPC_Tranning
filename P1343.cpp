#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
vector<int>mp[2070];
int tot=1;
int d[2070];
int e[2070];
int pre[2070];
int incf[2070];
int v[2070];
int n,m,x;
vector<ll>ans;
int maxflow=0;
int cnt=0;
void add(int x,int y,int c)
{
    d[++tot]=y;
    e[tot]=c;
    mp[x].push_back(tot);
    d[++tot]=x;
    e[tot]=0;
    mp[y].push_back(tot);
}
int bfs()
{
    memset(v,0,sizeof(v));
    v[1]=1;
    queue<int>q;
    q.push(1);
    incf[1]=INF;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<mp[t].size();i++){
            int x=mp[t][i];
            int y=d[x];
            if(e[x]){
                if(v[y])continue;
                incf[y]=min(incf[t],e[x]);
                pre[y]=x;
                q.push(y);
                v[y]=1;
                if(y==n)return 1;
            }
        }
    }
    return 0;
}
void update()
{
    int x=n;
    while(x!=1)
    {
        //cout<<x<<endl;
        int i=pre[x];
        e[i]-=incf[n];
        e[i^1]+=incf[n];
        x=d[i^1];
    }
    //cout<<incf[n]<<endl;
    maxflow+=incf[n];
    cnt++;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kk;
    cin>>n>>m>>kk;
    int x,y,z;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);
    }
    while(bfs())update();
    if(maxflow==0)cout<<"Orz Ni Jinan Saint Cow!";
    else cout<<maxflow<<' '<<ceil((double)kk*1.0/maxflow);
    //cout.flush();
    //system("pause");
    return 0;
}