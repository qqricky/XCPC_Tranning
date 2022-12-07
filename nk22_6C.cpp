#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
char mp[570][570];
bool flag=0;
int n,m;
bool g1[570][570];
bool g2[570][570];
bool g3[570][570];
bool f1[570][570];
bool f3[570][570];
bool f2[570][570];
bool vis[570][570];
void dfs(int x,int y){
    if(x>n||y>m)return;
    if(vis[x][y])return;
    vis[x][y]=1;
    if(mp[x][y]=='A'){
        g1[x][y]=1;
        f3[x][y]=1;
        return;
    }else if(mp[x][y]=='B'){
        g2[x][y]=1;
        f1[x][y]=1;
        return;
    }else if(x==n&&y==m){
        f2[x][y]=1;
        g3[x][y]=1;
        return;
    }
    dfs(x+1,y),dfs(x,y+1);
    //alice必胜
    g1[x][y]=(f3[x+1][y]|f3[x][y+1]);
    //bob必平
    if(x<n&&y<m)g3[x][y]=(f2[x+1][y]&f2[x][y+1]);
    else if(x<n)g3[x][y]=(f2[x+1][y]);
    else    g3[x][y]=(f2[x][y+1]);
    //bob必胜
    if(x<n&&y<m)f1[x][y]=(g2[x+1][y]&g2[x][y+1]);
    else if(x<n)f1[x][y]=(g2[x+1][y]);
    else   f1[x][y]=(g2[x][y+1]);
    //bob必败
    if(x<n&&y<m)f3[x][y]=(g1[x+1][y]&g1[x][y+1]);
    else if(x<n)f3[x][y]=(g1[x+1][y]);
    else f3[x][y]=(g1[x][y+1]);
    //alice可败
    g2[x][y]=(f1[x+1][y]|f1[x][y+1]);
    //alice可平
    f2[x][y]=(g3[x+1][y]|g3[x][y+1]);
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        memset(g1,0,sizeof(g1));
        memset(g2,0,sizeof(g2));
        memset(g3,0,sizeof(g3));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(f3,0,sizeof(f3));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        dfs(1,1);
        if(g1[1][1])cout<<"yes ";
        else cout<<"no ";
        if(f2[1][1])cout<<"yes ";
        else cout<<"no ";
        if(g2[1][1])cout<<"yes\n";
        else cout<<"no\n";
    }
    // cout.flush();
    // system("pause");
    return 0;
}