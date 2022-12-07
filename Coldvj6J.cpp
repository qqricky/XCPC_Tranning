#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#define ll long long
#define INF 0x3f3f3f3f
const int N=10700; 
using namespace std;
int dis[150];
int v[150];
int d[N];
int w[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    int s,t;
    while(cin>>n>>m)
    {
        int tot=0;
        memset(dis,0x3f,sizeof(dis));
        memset(v,0,sizeof(v));
        vector<int>mp[150];
        for(int i=1;i<=m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(x==y)continue;
            tot++;
            mp[x].push_back(tot);
            d[tot]=y;
            w[tot]=z;
            tot++;
            mp[y].push_back(tot);
            d[tot]=x;
            w[tot]=z;
        }
        cin>>s>>t;
        v[s]=1;
        queue<int>q;
        q.push(s);
        dis[s]=0;
        while(q.size())
        {
            int k=q.front();
            v[k]=0;
            q.pop();
            int a;
            for(int j=0;j<mp[k].size();j++){
                a=mp[k][j];
                if(dis[d[a]]>dis[k]+w[a]){
                    dis[d[a]]=dis[k]+w[a];
                    if(!v[d[a]]){
                        q.push(d[a]);
                        v[d[a]]=1;    
                    }
                }
            }
        }
        if(dis[t]>5000000)cout<<"-1\n";
        else cout<<dis[t]<<"\n";
    }
    //system("pause");
    return 0;
}