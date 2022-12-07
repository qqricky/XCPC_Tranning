#include <bits/stdc++.h>
#define ll long long
//#pragma GCC optimise(2)
using namespace std;
vector<int>mp[100];
const int maxn=100100;
const int maxm=300100;
const int INF=0x3f3f3f3f;
struct edge{
	int to,next;
	int cap,flow;
}edge[maxm];
int tol;
int head[maxn];
int gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init(){
	tol=2;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0){
	edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
	edge[tol].flow=0;head[u]=tol++;
	edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
	edge[tol].flow=0;head[v]=tol++;
}
int Q[maxn];
int sta[maxn];
bool bfs(int s,int t,int n){
	int front =0,tail =0;
	memset(dep,-1,sizeof(dep[0])*(n+1));
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
int main()
{
    //freopen("C:/Users/14254/Downloads/P2762_2.in","r",stdin);
    //freopen("C:/Users/14254/Downloads/P2762_2(2).out","w",stdout);
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0);
    // cout.tie(0);
    int n,m,s,t;
	scanf("%d %d",&m,&n);
    s=1,t=n+m+2;
	init();
    int ans=0;
	for(int i=1;i<=m;i++){
		int pp;
        scanf("%d",&pp);
        ans+=pp;
        addedge(s,i+1,pp);
        char tools[10000];
        memset(tools,0,sizeof tools);
        cin.getline(tools,10000);
        int ulen=0,tool;
        while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
        {//tool是该实验所需仪器的其中一个      
            //这一行，你可以将读进来的编号进行储存、处理，如连边。
            addedge(i+1,tool+m+1,INF);
            mp[i].push_back(tool);
            if (tool==0) 
                ulen++;
            else {
                while (tool) {
                    tool/=10;
                    ulen++;
                }
            }
            ulen++;
        }
	}
    int ppp;
    for(int i=1;i<=n;i++){
        scanf("%d",&ppp);
        addedge(i+m+1,t,ppp);
    }
	ans-=dinic(s,t,n+m+2);
    // for(int i=0;i<tol;i++){
    //     if(edge[i].cap>0&&edge[i].cap==edge[i].flow&&edge[i].now==s){
    //         vis[edge[i].to-1]=1;
    //     }
    // }
    // for(int j=1;j<=m;j++){
    //     if(!vis[j]){
    //         cout<<j<<' ';
    //         for(int i : mp[j]){
    //             cs[i]=1;
    //         }
    //     }
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     if(cs[i])cout<<i<<' ';
    // }
    for(int i=1;i<=m;i++){
        if(dep[i+1]>0){
            cout<<i<<' ';
        }
    }
    cout<<"\n";
    for(int i=m+2;i<=n+m+1;i++){
        if(dep[i]>0){
            cout<<i-1-m<<' ';
        }
    }
    cout<<'\n';
	cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}