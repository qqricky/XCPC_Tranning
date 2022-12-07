#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
using namespace std;
const int maxn=1e5+10;
const int maxm=4e5+10;
struct edge{
    int to,next,cap,flow;
}edge[maxm];
int tol;
int head[maxn];
int gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init(){
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0){
    edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
    edge[tol].flow=0;head[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
    edge[tol].flow=0;head[v]=tol++;
}
int sap(int start,int end,int N){
    memset(dep,0,sizeof(dep));
    memset(dep,0,sizeof(dep));
}

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    
    cout.flush();
    system("pause");
    return 0;
}