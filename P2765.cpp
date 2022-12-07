#include <bits/stdc++.h>
#define ll long long
//#pragma GCC optimise(2)
using namespace std;
const int maxn=100100;
const int maxm=300100;
const int INF=0x3f3f3f3f;
struct edge{
	int to,next;
    int now;
	int cap,flow;
}edge[maxm];
int tol;
int head[maxn];
int gap[maxn],dep[maxn],pre[maxn],cur[maxn];
int var[maxn];
void init(){
	tol=2;
	memset(head,-1,sizeof(head));
    for(int i=2;i<=501;i++){
        var[i-1]=i*i;
    }
}
void addedge(int u,int v,int w,int rw=0){
    edge[tol].now=u;
	edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
	edge[tol].flow=0;head[u]=tol++;
    edge[tol].now=v;
	edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
	edge[tol].flow=0;head[v]=tol++;
}
int Q[maxn];
int sta[maxn];
bool bfs(int s,int t,int n){
	int front =0,tail =0;
	memset(dep,-1,sizeof(dep[0])*(n+2));
	dep[s]=0;
	Q[tail++]=s;
	while(front<tail){
		int u=Q[front++];
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>edge[i].flow&&dep[v]==-1){
				dep[v]=dep[u]+1;
				if(v==t)return true;
				Q[tail++]=v;
			}
		}
	}
	return false;
}
int dinic(int s,int t,int n){
	int maxflow=0;
	while(bfs(s,t,n)){
		for(int i=0;i<=n;i++)cur[i]=head[i];
		int u=s,tail=0;
		while(cur[s]!=-1){
			if(u==t){
				int tp=INF;
				for(int i=tail-1;i>=0;i--)
					tp=min(tp,edge[sta[i]].cap-edge[sta[i]].flow);
				maxflow+=tp;
				for(int i=tail-1;i>=0;i--){
					edge[sta[i]].flow+=tp;
					edge[sta[i]^1].flow-=tp;
					if(edge[sta[i]].cap-edge[sta[i]].flow==0)
						tail=i;
				}
				u=edge[sta[tail]^1].to;
			}
			else if(cur[u]!=-1&&edge[cur[u]].cap>edge[cur[u]].flow&&dep[u]+1==dep[edge[cur[u]].to]){
				sta[tail++]=cur[u];
				u=edge[cur[u]].to;
			}
			else{
				while(u!=s&&cur[u]==-1)
					u=edge[sta[--tail]^1].to;
				cur[u]=edge[cur[u]].next;
			}
		}
	}
	return maxflow;
}
int ind[maxn]={};
int ne[maxn]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin>>n;
    int s=0,t=1;
    int ans=0;
    int now=0;
    int mf=0;
    // for(int i=1;i<=11;i++){
    //     addedge(s,2*i,1);
    //     addedge(2*i+1,t,1);
    //     for(int j=1;j<=8;j++){
    //         if(var[j]<=i)continue;
    //         int val=var[j]-i;
    //         if(val>=i)continue;
    //         addedge(2*val,2*i+1,1);
    //     }
    // }
    // dinic(s,t,2*11+2);
    // now=12;
    while(ans<n+1){
        ++now;
        addedge(s,2*now,1);
        addedge(2*now+1,t,1);
        for(int i=1;i<=500;i++){
            if(var[i]<=now)continue;
            int val=var[i]-now;
            if(val>=now)break;
            addedge(2*val,2*now+1,1);
        }
        mf+=dinic(s,t,2*now+2);
        ans=now-mf;
    }
    now--;
    ans--;
    for(int i=1;i<=now;i++)ne[i]=i;
    cout<<now<<'\n';
    for(int i=2;i<tol;i++){
        if(edge[i].now>s&&edge[i].to!=t&&edge[i].flow>0){
            ne[(edge[i].now)/2]=(edge[i].to)/2;
            ind[(edge[i].to)/2]++;
        }
    }
    for(int i=1;i<=now;i++){
        if(ind[i]==0){
            int u=i;
            while(ne[u]!=u){
                cout<<u<<' ';
                u=ne[u];
            }
            cout<<u<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}