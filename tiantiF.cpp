#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
const ll mod=1e9+7;
struct node
{
    int pos;
    int mo;
};
vector<node>v;
bool cmp(node x,node y)
{
    return x.mo>y.mo;
}
struct edge
{
    int x,y;
    int val;
    int val2;
}mpp[2*N];
vector<int>mp[N];
int vis[N]={};
int f[N];
map<pair<int,int>,int>ex;
int cnt=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    int u,v,c,d;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>c>>d;
        if(u==v)continue;
        edge dd;
        dd.x=u;
        dd.y=v;
        dd.val=c;
        dd.val2=d;
        mpp[++cnt]=dd;
        if(ex[make_pair(u,v)]){
            for(int j=0;j<mp[u].size();j++){
                int kk=mp[u][j];
                if(mpp[kk].y==v){
                    mpp[kk].val=min(mpp[kk].val,c);
                    mpp[kk].val2=min(mpp[kk].val2,d);
                }
            }
            ex[make_pair(u,v)]=1;
        }
        else{
            mp[u].push_back(cnt);
        }
    }
    memset(f,0x3f,sizeof(f));
    vis[1]=1;
    queue<int>qq;
    qq.push(1);
    while(qq.size()){
        int k=qq.front();
        qq.pop();
        vis[k]==0;
        int p;
        for(int j=0;j<=mp[k].size();j++){
            p=mp[k][j];
            if(vis[mpp[p]])
        }
    }
    int x,y;
    for(int i=1;i<=q;i++){
        
    }
    //system("pause");
    return 0;
}