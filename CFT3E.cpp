#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int head[N]={};
int v[10070]={};
int ne[N]={};
int s[N];
int l[N];
int tot=0;
struct node{
    int w;
    int num;   
};
bool operator < (const node &a, const node &b){
        return a.w>b.w;
    }
int dis[10070]={};
void add(int x,int y,int z)
{
    s[++tot]=y;
    l[tot]=z;
    ne[tot]=head[x];head[x]=tot;
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
    node a;
    priority_queue<node>q;
    for(int i=1;i<=n;i++){
        cin>>a.w;
        dis[i]=a.w;
        a.num=i;
        q.push(a);
    }
    int x,y,z;
    if(m==0)goto paris;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        add(x+1,y+1,z);
    }
    while(q.size())
    {
        node pos=q.top();
        while(v[pos.num]){
            q.pop();
            if(q.empty()){
                goto paris;
            }
            pos=q.top();
        }
        q.pop();
        v[pos.num]=1;
        for(int j=head[pos.num];j;j=ne[j]){
            if(!v[s[j]]&&dis[s[j]]>dis[pos.num]+l[j]){
                dis[s[j]]=dis[pos.num]+l[j];
                node tt;
                tt.num=s[j];
                tt.w=dis[s[j]];
                q.push(tt);
            }
        }
    }
    paris:;
    ll ans=0;
    ll tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        ans+=tmp*dis[i];
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}