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
char mp[1070][1070]={};
bool vis[1070][1070]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    queue<pair<int,int> >q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='O'){
                num++;
                if(mp[i-1][j]=='v'){
                    q.push(make_pair(i-1,j));
                    vis[i-1][j]=1;
                    num++;
                }
                if(mp[i+1][j]=='^'){
                    q.push(make_pair(i+1,j));
                    vis[i+1][j]=1;
                    num++;
                }
                if(mp[i][j+1]=='<'){
                    q.push(make_pair(i,j+1));
                    vis[i][j+1]=1;
                    num++;
                }
                if(mp[i][j-1]=='>'){
                    q.push(make_pair(i,j-1));
                    vis[i][j-1]=1;
                    num++;
                }
            }
        }
    }
    while(!q.empty()){
        pair<int,int>pr=q.front();
        int x=pr.first;
        int y=pr.second;
        //cout<<x<<' '<<y<<endl;
        q.pop();
        if(mp[x-1][y]=='v'){
            if(!vis[x-1][y]){
                q.push(make_pair(x-1,y));
                vis[x-1][y]=1;
                num++;
            }
        }
        if(mp[x+1][y]=='^'){
            if(!vis[x+1][y]){
                q.push(make_pair(x+1,y));
                vis[x+1][y]=1;
                num++;
            }
        }
        if(mp[x][y+1]=='<'){
            if(!vis[x][y+1]){
                q.push(make_pair(x,y+1));
                vis[x][y+1]=1;
                num++;
            }
        }
        if(mp[x][y-1]=='>'){
            if(!vis[x][y-1]){
                q.push(make_pair(x,y-1));
                vis[x][y-1]=1;
                num++;
            }
        }
    }
    cout<<num;
    cout.flush();
    //system("pause");
    return 0;
}