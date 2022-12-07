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
bool ck(int x,int y){
    if(mp[x+1][y]=='X'||mp[x][y+1]=='X')return 1;
    if(mp[x][y+1]=='X'||mp[x][y-1]=='X')return 1;
    return 0;
}
bool ckk(int x,int y){
    if(mp[x+1][y]=='X')return 1;
    if(mp[x][y+1]=='X'||mp[x][y-1]=='X')return 1;
    return 0;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int x=INF,y=INF;
        bool is=0;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                mp[i][j]='@';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='X'){
                    is=1;
                    if(j<y){
                        x=i;
                        y=j;
                    }
                }
            }
        }
        if(is){
            
            // for(int i=1;i<=n;i++)mp[i][y]='X';
            // for(int j=1;j<=m;j++)mp[x][j]='X';
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=m;j++){
            //         if(mp[i][j]=='X'&&(!ck(i,j))){
            //             for(int k=j-1;k>=y;k--){
            //                 if(!ckk(i,k))mp[i][k]='X';
            //             }
            //         }
            //     }
            // }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<mp[i][j];
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}