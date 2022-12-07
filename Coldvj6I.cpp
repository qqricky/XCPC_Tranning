#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int mp[150][150];
int dis[150];
int v[150];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    while(n)
    {
        int x,y,z;
        ll ans=0;
        memset(mp,0x3f,sizeof(mp));
        memset(dis,0xef,sizeof(dis));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n*(n-1)/2;i++){
            cin>>x>>y>>z;
            mp[x][y]=mp[y][x]=z;
        }
        int pos=1;
        v[1]=1;
        for(int i=2;i<=n;i++)dis[i]=mp[1][i];
        for(int i=2;i<=n;i++){
            int mi=INF;
            for(int j=1;j<=n;j++){
                if(!v[j]&&dis[j]<mi){
                    mi=dis[j];
                    pos=j;
                }
            }
            v[pos]=1;
            ans+=mi;
            for(int j=1;j<=n;j++){
                if(!v[j]&&dis[j]>mp[pos][j]){
                    dis[j]=mp[pos][j];
                }
            }
        }
        std::cout<<ans<<endl;
        cin>>n;
    }
    //system("pause");
    return 0;
}