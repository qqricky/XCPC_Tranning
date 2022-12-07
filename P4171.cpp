#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
const int M=2*N;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct Edge{
    int to,next;
}edge[M];
int head[N],tot;
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
    edge[tot].to=v;edge[tot].next=head[u];head[u]=tot++;
}
int Low[N],DFN[N],Stack[N],Belong[N];
int Index,top;
int scc;
bool Instack[N];
int num[N];
void Tarjan(int u){
    int v;
    Low[u]=DFN[u]=++Index;
    Stack[top++]=u;
    Instack[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        v=edge[i].to;
        if(!DFN[v]){
            Tarjan(v);
            if(Low[u]>Low[v])Low[u]=Low[v];
        }
        else if(Instack[v]&&Low[u]>DFN[v])
            Low[u]=DFN[v];
    }
    if(Low[u]==DFN[u]){
        scc++;
        do{
            v=Stack[--top];
            Instack[v]=0;
            Belong[v]=scc;
            num[scc]++;
        }
        while(v!=u);
    }
}
bool solvable(int n){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index=scc=top=0;
    for(int i=0;i<n;i++){
        if(!DFN[i])
            Tarjan(i);
    }
    for(int i=0;i<n;i+=2){
        if(Belong[i]==Belong[i^1]){
            return 0;
        }
    }
    return 1;
}
queue<int>q1,q2;
vector<vector<int> >dag;
char color[N];
int indeg[N];
int cf[N];
void solve(int n){
    dag.assign(scc+1,vector<int>());
    memset(indeg,0,sizeof(indeg));
    memset(color,0,sizeof(color));
    for(int u=0;u<n;u++){
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(Belong[u]!=Belong[v]){
                dag[Belong[v]].push_back(Belong[u]);
                indeg[Belong[u]]++;
            }
        }
    }
    // for(int i=0;i<n;i+=2){
    //     cf[Belong[i]]=Belong[i^1];
    //     cf[Belong[i^1]]=Belong[i];
    // }
    for(int i=1;i<=scc;i++)
        if(indeg[i]==0)
            q1.push(i);
    while(!q1.empty()){
        int u=q1.front();
        q1.pop();
        if(color[u]==0){
            color[u]='R';
            color[cf[u]]='B';
        }
        int sz=dag[u].size();
        for(int i=0;i<sz;i++){
            indeg[dag[u][i]]--;
            if(indeg[dag[u][i]]==0){
                q1.push(dag[u][i]);
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
    int n,m,u,v;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        init();
        bool x,y;
        for(int i=1;i<=m;i++){
            char ch1,ch2;
            cin>>ch1>>u>>ch2>>v;
            if(ch1=='m')x=0;
            else x=1;
            if(ch2=='m')y=0;
            else y=1;
            //u--,v--;
            u--,v--;
            u*=2,v*=2;
            if(x&&y){
                addedge(u^1,v);
                addedge(v^1,u);
            }
            else if(x){
                addedge(u^1,v^1);
                addedge(v,u);
            }
            else if(y){
                addedge(v^1,u^1);
                addedge(u,v);
            }
            else{
                addedge(v,u^1);
                addedge(u,v^1);
            }
        }
        //addedge(1,0);
        if(solvable(2*n)){
            // solve(2*n);
            cout<<"GOOD\n";
        }
        else cout<<"BAD\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}