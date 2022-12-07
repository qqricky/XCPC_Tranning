#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
bool vis[105];
bool mp[102][102];
int s;
int ans=0;
void dfs(int now,int last,vector<int>v)
{
    for(int i=last-1;i>=1;i--){
        if(!vis[i]){
            int flag=1;
            for(int j=0;j<v.size();j++){
                if(mp[i][v[j]]==0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                if(now==s-1){
                    ans++;
                    continue;
                }
                vis[i]=1;
                v.push_back(i);
                dfs(now+1,i,v);
                vis[i]=0;
                v.pop_back();
            }
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m>>s;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mp[i][j]=mp[j][i]=0;
            }
        }
        memset(vis,0,sizeof(bool)*n);
        ans=0;
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            mp[x][y]=1;
            mp[y][x]=1;
        }
        vector<int>tmp;
        for(int i=n;i>=s;i--){
            tmp.push_back(i);
            vis[i]=1;
            dfs(1,i,tmp);
            tmp.pop_back();
            vis[i]=0;
        }
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}