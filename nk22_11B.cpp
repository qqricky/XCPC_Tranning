#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f
//#pragma GCC optimise(2)
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=2e3+10;
const int maxm=5e6+10;
bool vis[maxn];int dist[maxn];
int n,nn,k,s,t,ans=0;
int nedge=-1,p[maxm],c[maxm],cc[maxm],nex[maxm],head[maxn];
//这里是边表，解释一下各数组的含义：p[i]表示以某一点出发的编号为i的边对应点，c表示编号为i的边的流量，cc表示编号为i的边的费用，nex和head不说了吧。。。
inline void addedge(int x,int y,int z,int zz){
    p[++nedge]=y;c[nedge]=z;cc[nedge]=zz;nex[nedge]=head[x];head[x]=nedge;
}
inline void add(int x,int y,int z,int zz){
    addedge(x,y,z,zz);addedge(y,x,0,-zz);
}
inline bool spfa(int s,int t){
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)dist[i]=1e9;dist[t]=0;vis[t]=1;
    deque<int>q;q.push_back(t);
    while(!q.empty()){
        int now=q.front();q.pop_front();
        for(int k=head[now];k>-1;k=nex[k])if(c[k^1]&&dist[p[k]]>dist[now]-cc[k]){
            dist[p[k]]=dist[now]-cc[k];
            if(!vis[p[k]]){
                vis[p[k]]=1;
                if(!q.empty()&&dist[p[k]]<dist[q.front()])q.push_front(p[k]);else q.push_back(p[k]);
            }
        }
        vis[now]=0;
    }
    return dist[s]<1e9;
}
inline int dfs(int x,int low){
    if(x==t){vis[t]=1;return low;}
    int used=0,a;vis[x]=1;
    for(int k=head[x];k>-1;k=nex[k])if(!vis[p[k]]&&c[k]&&dist[x]-cc[k]==dist[p[k]]){
        a=dfs(p[k],min(c[k],low-used));
        if(a)ans+=a*cc[k],c[k]-=a,c[k^1]+=a,used+=a;
        if(used==low)break;
    }
    return used;
}
inline int costflow(){
    int flow=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof vis);
            flow+=dfs(s,1e9);
        }
    }
    return flow;
}


int res[maxn];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>nn>>k;
    n=nn+k+2;
    s=nn+k+1,t=nn+k+2;
    memset(nex,-1,sizeof nex);memset(head,-1,sizeof head);
    for(int i=1;i<=nn;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.length();j++){
            if(str[j]=='1'){
                add(j+1,k+i,1,0);
            }
        }
        add(k+i,t,1,0);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=nn;j++){
            add(s,i,1,j);
        }
    }
    int flow=costflow();
    // cout<<flow<<' '<<ans<<endl;
    if(flow!=nn){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=k;i++){
        for(int j=head[i];j!=-1;j=nex[j]){
            if(p[j]==s)continue;
            if(c[j]==0){
                res[p[j]-k]=i;
            }
        }
    }
    for(int i=1;i<=nn;i++)cout<<res[i]<<' ';
    // cout.flush();
    // system("pause");
    return 0;
}