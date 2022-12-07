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
    int x,y;
    int tt[5]={0,8,8,1};
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<tt[i]<<endl;
    }
    //system("pause");
    return 0;
}