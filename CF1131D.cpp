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
int n,m;
int f[3070];
char mp[1070][1070];
vector<int>v[3070];
int ans[3070];
int vis[3070];
int deg[3070]={};
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x==y)return ;
    if(x>y)swap(x,y);
    f[x]=y;
    deg[y]+=deg[x];
}
map<pair<int,int>,int>is;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int tot=0;
    for(int i=1;i<=n+m;i++)f[i]=i;
    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='='){
                merge(i,j+n);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='>'){
                int x=getfa(j+n);
                int y=getfa(i);
                if(x==y){
                    flag=0;
                    break;
                }
                if(is[make_pair(x,y)])continue;
                v[x].push_back(y);
                is[make_pair(x,y)]=1;
                deg[y]++;
            }
            else if(mp[i][j]=='<'){
                int y=getfa(j+n);
                int x=getfa(i);
                if(x==y){
                    flag=0;
                    break;
                }
                if(is[make_pair(x,y)])continue;
                v[x].push_back(y);
                is[make_pair(x,y)]=1;
                deg[y]++;
            }
        }
        if(!flag)break;
    }
    if(!flag){
        cout<<"No";
        return 0;
    }
    set<int>s;
    queue<int>q;
    set<int>st;
    for(int i=1;i<=n+m;i++){
        int tmp=getfa(i);
        st.insert(tmp);
        if(deg[tmp]==0&&s.count(tmp)==0){
            q.push(tmp);
            s.insert(tmp);
            ans[tmp]=1;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int x:v[u]){
            x=getfa(x);
            ans[x]=max(ans[x],ans[u]+1);
            deg[x]--;
            if(deg[x]<=0){
                q.push(x);
                s.insert(x);
            }
        }
    }
    if(s.size()!=st.size()){
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        cout<<ans[getfa(i)]<<' ';
    }
    cout<<'\n';
    for(int i=n+1;i<=n+m;i++){
        cout<<ans[getfa(i)]<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}