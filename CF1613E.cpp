#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,m;
vector<char>mp[N];
void dfs(int x,int y){
    if(mp[x][y]!='.')return;
    int can= (mp[x+1][y]=='.')+(mp[x][y+1]=='.')
            +(mp[x][y-1]=='.')+(mp[x-1][y]=='.');
    if(can>=2)return;
    mp[x][y]='+';
    if(mp[x][y+1]=='.')dfs(x,y+1);
    if(mp[x+1][y]=='.')dfs(x+1,y);
    if(mp[x][y-1]=='.')dfs(x,y-1);
    if(mp[x-1][y]=='.')dfs(x-1,y);
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
    while(t--){
        cin>>n>>m;
        char ch;
        int x0,y0;
        mp[0].clear();mp[n+1].clear();
        for(int j=0;j<=m;j++){
            mp[0].push_back('#');
            mp[n+1].push_back('#');
        }
        for(int i=1;i<=n;i++){
            mp[i].clear();
            mp[i].push_back('#');
            for(int j=1;j<=m;j++){
                cin>>ch;
                if(ch=='L'){
                    x0=i;
                    y0=j;
                }
                mp[i].push_back(ch);
            }
            mp[i].push_back('#');
        }
        dfs(x0+1,y0);
        dfs(x0-1,y0);
        dfs(x0,y0+1);
        dfs(x0,y0-1);
        mp[x0][y0]='L';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<mp[i][j];
            }
            cout<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}