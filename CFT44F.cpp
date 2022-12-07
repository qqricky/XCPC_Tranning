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
struct nodee
{
    int x,w;
    bool operator<(const nodee &b)const{
        return w>b.w;
    }
};

struct node
{
    int k,id,pos;
}nd[N];
bool cmp(node a,node b){
    return a.k<b.k;
}
set<pair<int,int> >mp[N];
int a[N];
int fa[N];
int sz[N]={};
ll val[N]={};
int getfa(int x){
    return x==fa[x] ? x : fa[x]=getfa(fa[x]);
}
bool vis[N]={};
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x==y)return;
    if(sz[x]>sz[y]){
        swap(x,y);
    }
    val[y]+=val[x];
    fa[x]=y;
    sz[y]--,sz[x]--;
    sz[y]+=sz[x];
    for(auto pr:mp[x]){
        if(getfa(pr.second)==y){
            sz[y]--;
            continue;
        }
        mp[y].insert(pr);
    }
}
int ans[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        val[i]=a[i];
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        sz[x]++,sz[y]++;
        mp[x].insert(make_pair(z,y));
        mp[y].insert(make_pair(z,x));
    }
    for(int i=1;i<=q;i++){
        cin>>nd[i].pos>>nd[i].k;
        nd[i].id=i;
    }
    sort(nd+1,nd+q+1,cmp);
    for(int i=1;i<=q;i++){
        int pos=nd[i].pos;
        pos=getfa(pos);
        auto pr=make_pair(val[pos]+nd[i].k,0);
        auto it=mp[pos].upper_bound(pr);
        priority_queue<nodee>q;
        for(auto itr=mp[pos].begin();itr!=it;itr++){
            q.push((nodee){itr->second,itr->first});
        }
        while(!q.empty()){
            auto x=q.top();
            if(x.w>nd[i].k+val[getfa(pos)]){
                ans[nd[i].id]=nd[i].k+val[getfa(pos)];
                break;
            }
            q.pop();
            if(getfa(x.x)==getfa(pos))continue;
            merge(getfa(x.x),getfa(pos));
            int now=getfa(x.x);
            auto pr=make_pair(val[now]+nd[i].k,0);
            auto it=mp[now].upper_bound(pr);
            for(auto itr=mp[now].begin();itr!=it;itr++){
                q.push((nodee){itr->second,itr->first});
            }
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    cout.flush();
    system("pause");
    return 0;
}