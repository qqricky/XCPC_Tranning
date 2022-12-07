#include <bits/stdc++.h>
#define ll long long
#define INF 1e16
//#pragma GCC optimise(2)
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=1e4+10;
const int maxm=1e5+10;
struct edge{
    int now;
    ll to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
ll dis[maxn];
bool vis[maxn];
int N;
void init(int n){
    N=n;
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,ll cap,int cost){
    edge[tol].now=u;
    edge[tol].to=v;
    edge[tol].cap=cap;
    edge[tol].cost=cost;
    edge[tol].flow=0;
    edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].now=v;
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].cost=-cost;
    edge[tol].flow=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}
bool spfa(int s,int t){
    queue<int>q;
    for(int i=0;i<N;i++){
        dis[i]=INF;
        vis[i]=0;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow && dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1)return false;
    else return true;
}
int minCostMaxflow(int s,int t,ll &cost){
    ll flow=0;
    cost=0;
    while(spfa(s,t)){
        ll Min=INF;
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            if(Min>edge[i].cap-edge[i].flow)
                Min=edge[i].cap-edge[i].flow;
        }
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }
        flow+=Min;
    }
    return flow;
}
map<string,int>mp;
string rmp[maxn];
bool vi[maxn]={};
int ne[maxn];
vector<int>ansv[2];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int s=0,t=1;
    init(2*n+2);
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(i==1||i==n){
            addedge(i*2,i*2+1,2,-1);
        }
        else{
            addedge(i*2,i*2+1,1,-1);
        }
        string str;
        cin>>str;
        mp[str]=i;
        rmp[i]=str;
    }
    for(int i=1;i<=m;i++){
        string str1,str2;
        cin>>str1>>str2;
        if(mp[str1]==1&&mp[str2]==n)flag=1;
        addedge(mp[str1]*2+1,mp[str2]*2,1,0);
    }
    addedge(s,2,INF,0);
    addedge(2*n+1,t,INF,0);
    ll ans=0;
    int maxflow=minCostMaxflow(0,1,ans);
    if(maxflow<2){
        if(flag){
            cout<<2<<'\n';
            cout<<rmp[1]<<'\n'<<rmp[n]<<'\n'<<rmp[1];
            return 0;
        }
        cout<<"No Solution!";
        return 0;
    }
    cout<<-ans-2<<'\n';
    for(int i=1;i<=n;i++)ne[i]=i;
    for(int i=0;i<tol;i++){
        if(edge[i].cost!=0)continue;
        if(edge[i].now>edge[i].to)continue;
        if(edge[i].now>3&&edge[i].to<2*n&&edge[i].flow>0){
            edge[i].now/=2;
            edge[i].to/=2;
            // cout<<edge[i].now<<' '<<edge[i].to<<endl;
            // cout<<rmp[edge[i].now]<<"--> "<<rmp[edge[i].to]<<endl;
            ne[edge[i].now]=edge[i].to;
            vi[edge[i].now]=vi[edge[i].to]=1;
        }
    }
    int cnt=0;
    for(int i=2;i<n;i++){
        if(vi[i]){
            int val=i;
            while(ne[val]!=val){
                ansv[cnt].push_back(val);
                vi[val]=0;
                val=ne[val];
            }
            ansv[cnt].push_back(val);
            vi[val]=0;
            cnt++;
        }
    }
    // cout<<endl;
    // for(int i:ansv[0]){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    // for(int i: ansv[1]){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    cout<<rmp[1]<<'\n';
    for(int val : ansv[0]){
        cout<<rmp[val]<<'\n';
    }
    cout<<rmp[n]<<'\n';
    reverse(ansv[1].begin(),ansv[1].end());
    for(int val : ansv[1]){
        cout<<rmp[val]<<'\n';
    }
    cout<<rmp[1]<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}