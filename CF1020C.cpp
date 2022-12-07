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
int n,m,num=0;
bool vis[3070];
struct node{
    int id,c;
};
vector<node>nd;
vector<node>pt[3070];
ll ck(int val){
    ll cost=0;
    int tmp=num;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=m;i++){
        for(int j=0;j<max(0,(int)pt[i].size()-val+1);j++){
            //cout<<j<<' '<<pt[i].size()<<' '<<1-val<<endl;
            cost+=pt[i][j].c;
            tmp++;
            vis[pt[i][j].id]=1;
        }
    }
    int pos=0;
    while(tmp<val){
        if(!vis[nd[pos].id]){
            tmp++;
            cost+=nd[pos].c;
            vis[nd[pos].id]=1;
        }
        pos++;
    }
    return cost;
}
bool cmp(node a,node b){
    return a.c<b.c;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x==1)num++;
        else{
            pt[x].push_back((node){i,y});
            nd.push_back((node){i,y});
        }
    }
    sort(nd.begin(),nd.end(),cmp);
    for(int i=2;i<=m;i++){
        sort(pt[i].begin(),pt[i].end(),cmp);
    }
    ll ans=1e18;
    for(int i=max(1,num);i<=max(num,(n+1)/2);i++){
        ans=min(ans,ck(i));
    }
    cout<<ans<<endl;
    cout.flush();
    //system("pause");
    return 0;
}