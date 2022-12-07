#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
vector<int>rmp[N];
int fa[N][2]={};
bool vis[N]={},recStack[N]={};
bool vv[N]={};
queue<pair<int,int> >q;
bool isCyclicUtil(int v)
{
    if (!vis[v])
    {
        vis[v] = recStack[v] = true;
        for(int i = 0;i < rmp[v].size();++ i)
        {
            if (!vis[rmp[v][i]] && isCyclicUtil(rmp[v][i]))
                return true;
            else if (recStack[rmp[v][i]])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int n)
{
    for(int i = 1;i <= n;++ i)
    {
        if(!vv[i])continue;
        if (isCyclicUtil(i))
            return true;
    }
    return false;
}
void go(int now){
    vv[now]=1;
    for(int j=0;j<rmp[now].size();j++){
        if(!vv[rmp[now][j]]){ 
            go(rmp[now][j]);
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
    int n,m;
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++){
        cin>>m;
        if(!m){
            q.push(make_pair(i,0));
        }
        for(int j=1;j<=m;j++){
            cin>>x;
            mp[x].push_back(i);
            rmp[i].push_back(x);
        }
    }
    int st;
    cin>>st;
    bool flag=0;
    while(!q.empty()){
        pair<int,int>pr=q.front();
        if(pr.first==st&&pr.second==1){
            flag=1;
            cout<<"Win\n";
            int now=0;
            cout<<st<<' ';
            while(fa[st][now]){
                st=fa[st][now];
                now^=1;
                cout<<st<<' '; 
            }
            break;
        }
        q.pop();
        for(int j : mp[pr.first]){
            if(fa[j][pr.second]){
                continue;
            }
            fa[j][pr.second]=pr.first;
            q.push(make_pair(j,pr.second^1));
        }
    }
    if(!flag){
        go(st);
        bool fl=isCyclic(n);
        if(fl)cout<<"Draw";
        else cout<<"Lose";
    }
    cout.flush();
    //system("pause");
    return 0;
}