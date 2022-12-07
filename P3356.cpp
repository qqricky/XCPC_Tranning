#include <bits/stdc++.h>
#define ll long long
#define INF 1e16
#define inf 0x3f3f3f3f
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
    ll to,next,cap,flow,cost;
    int now;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
ll dis[maxn];
bool vis[maxn];
int N;
map<int,int>mpp[3200];
void init(int n){
    N=n;;
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,ll cap,int cost){
    cost=-cost;
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
int mp[100][100];
bool viss[100][100]={};
int n,m;
inline int calc(int x,int y){
    return m*(x-1)+y;
}
void dfs(int x,int y){
    viss[x][y]=1;
    if(mp[x+1][y]!=1 && !viss[x+1][y])dfs(x+1,y);
    if(mp[x][y+1]!=1 && !viss[x][y+1])dfs(x,y+1);
}
int cnt=0;
vector<int>can;
// void dfss(vector<int>v,int x,int y){
//     if(x==n&&y==m){
//         ++cnt;
//         for(int step : v){
//             cout<<cnt<<' '<<step<<'\n';
//         }
//         return ;
//     }
//     viss[x][y]=0;
//     if(viss[x+1][y]==1){
//         v.push_back(1);
//         dfss(v,x+1,y);
//         v.pop_back();
//     }
//     if(viss[x][y+1]==1){
//         v.push_back(0);
//         dfss(v,x,y+1);
//         v.pop_back();
//     }
// }
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int car;
    cin>>car;
    cin>>m>>n;
    init(n*m*2+2);
    int s=0,t=n*m*2+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=m;i++)mp[n+1][i]=1;
    for(int i=1;i<=n;i++)mp[i][m+1]=1;
    dfs(1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!viss[i][j]){
                mp[i][j]=1;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(mp[i][j]!=1){
    //             cout<<'#';
    //         }
    //         else cout<<' ';
    //     }
    //     cout<<'\n';
    // }
    addedge(s,1,car,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==1)continue;
            int rk=calc(i,j);
            addedge(rk*2-1,rk*2,inf,0);
            if(mp[i][j]==2){
                addedge(rk*2-1,rk*2,1,1);
            }
            if(mp[i+1][j]!=1){
                addedge(rk*2,calc(i+1,j)*2-1,inf,0);
            }
            if(mp[i][j+1]!=1){
                addedge(rk*2,calc(i,j+1)*2-1,inf,0);
            }
        }
    }
    addedge(n*m*2,t,inf,0);
    ll ans=0;
    minCostMaxflow(s,t,ans);
    for(int i=0;i<tol;i++){
        if(edge[i].flow>0&&edge[i].now<edge[i].to){
            int st=edge[i].now;
            int ed=edge[i].to;
            if(st%2==0&&ed!=t&&st!=s){
                int val=st/2;
                int val2=(ed+1)/2;
                mpp[val][val2]=edge[i].flow;
                // int x=val/m+1;
                // int y=val%m;
                // int xx=val2/m+1;
                // int yy=val2%m;
                // if(yy==0){
                //     xx--;
                //     yy=m;
                // }
                // if(y==0){
                //     x--;
                //     y=m;
                // }
                
                //cout<<xx<<' '<<yy<<' '<<edge[i].flow<<endl;
            }
        }
    }
    vector<int>tmp;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(viss[i][j]){
    //             cout<<'#';
    //         }
    //         else{
    //             cout<<' ';
    //         }
    //     }
    //     cout<<'\n';
    // }
    queue<pair<vector<int>,pair<int,int> > >q;
    q.push(make_pair(tmp,make_pair(1,1)));
    //cout<<ans<<endl;
    while(!q.empty()){
        pair<vector<int>,pair<int,int> >spr=q.front();
        q.pop();
        if(spr.first.size()==n+m-2){
            ++cnt;
            for(int dir : spr.first){
                cout<<cnt<<' '<<dir<<'\n';
            }
            continue;
        }
        int xx=spr.second.first;
        int yy=spr.second.second;
        //mp[xx][yy]=9;
        if(mpp[calc(xx,yy)][calc(xx+1,yy)]>0){
            mpp[calc(xx,yy)][calc(xx+1,yy)]--;
            pair<vector<int>,pair<int,int> >spp;
            spp=spr;
            spp.first.push_back(0);
            spp.second.first++;
            if(xx==1&&yy==2){
                cout<<"up"<<endl;
                for(int dir : spp.first){
                    cout<<dir<<' ';
                }
            }
            q.push(spp);
        }
        if(mpp[calc(xx,yy)][calc(xx,yy+1)]>0){
            mpp[calc(xx,yy)][calc(xx,yy+1)]--;
            pair<vector<int>,pair<int,int> >spp;
            spp=spr;
            spp.first.push_back(1);
            spp.second.second++;
            if(xx==1&&yy==2){
                spp.first[spp.first.size()-1]=inf;
                cout<<"down"<<endl;
                for(int dir : spp.first){
                cout<<dir<<' ';
            }
            cout<<"wwawawaw "<<endl;
            }
            q.push(spp);
        }
    }
    // while(cnt<car){
    //     cnt++;
    //     for(int i : can){
    //         cout<<cnt<<' '<<i<<'\n';
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<mp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout.flush();
    system("pause");
    return 0;
}