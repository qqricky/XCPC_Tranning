#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct edge {
  int x;
  ll w;
};
vector<edge>mp[2070];
ll xx[2070],yy[2070];
ll c[2070],k[2070];
ll dis[2070];
bool vis[2070]={};
int fr[2070]={};
ll ans=0;
vector<pair<int,int> >ansv;
vector<int>ansvv;
void dijkstra(int n, int s) {
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    int u = 0;
    ll mind = INF;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
    vis[u] = true;
    if(fr[u]==0){
        ansvv.push_back(u);
    }
    else{
        ansv.push_back(make_pair(fr[u],u));
    }
    ans+=dis[u];
    for (auto ed : mp[u]) {
      int v = ed.x;
      ll w = ed.w;
      if (dis[v] > w){
          dis[v] = w;
          fr[v]=u;
      }
    }
  }
}
ll calc_dis(int i,int j){
    return (abs(xx[i]-xx[j])+abs(yy[i]-yy[j]))*(k[i]+k[j]);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)dis[i]=INF;
    for(int i=1;i<=n;i++){
        cin>>xx[i]>>yy[i];
    }
    for(int i=1;i<=n;i++){cin>>c[i];dis[i]=c[i];}
    for(int i=1;i<=n;i++)cin>>k[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            mp[i].push_back((edge){j,calc_dis(i,j)});
        }
    }
    for(int i=1;i<=n;i++){
        mp[0].push_back((edge){i,c[i]});
    }
    dijkstra(n,0);
    cout<<ans<<'\n';
    cout<<ansvv.size()<<'\n';
    for(int i=0;i<ansvv.size();i++){
        cout<<ansvv[i]<<' ';
        if(i==ansvv.size()-1){
            cout<<'\n';
            break;
        }
    }
    cout<<ansv.size()<<'\n';
    for(int i=0;i<ansv.size();i++){
        cout<<ansv[i].first<<' '<<ansv[i].second<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}