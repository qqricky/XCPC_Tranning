#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int dis[150];
vector<int>mp[150];
int s[N],d[N],w[N];
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    while(n+m)
    {
        int x,y,z;
        memset(dis,0x3f,sizeof(dis));
        int tot=0;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>z;
            mp[x].push_back(++tot);
            s[tot]=x;
            d[tot]=y;
            w[tot]=z;
        }
        queue<int>q;
        dis[1]=0;
        q.push(1);
        int v[150]={};
        while(q.size())
        {
            int k=q.front();
            q.pop();
            v[x]=0;
            for(int j=0;j<mp[k].size();j++){
                if(dis[d[mp[k][j]]]>dis[s[mp[k][j]]]+w[mp[k][j]]){
                    dis[d[mp[k][j]]]=dis[s[mp[k][j]]]+w[mp[k][j]];
                    if(!v[d[mp[k][j]]])q.push(d[mp[k][j]]);
                }
            }
        }
        cout<<dis[n]<<endl;
        cin>>n>>m;
    }
    //system("pause");
    return 0;
}