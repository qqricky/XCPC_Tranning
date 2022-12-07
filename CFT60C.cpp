#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=4e4+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
bool is[N];
unordered_map<int,bool>mp[N];
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
        memset(is,0,sizeof(bool)*(n+3));
        for(int i=1;i<=n;i++){
            mp[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(z==1){
                is[x]^=1;
                is[y]^=1;
            }
            mp[x][y]=z;
            mp[y][x]=z;
        }
        while(m--){
            int tp;
            cin>>tp;
            if(tp){
                int x,y,z;
                cin>>x>>y>>z;
                if(mp[x][y]!=z){
                    mp[x][y]=z;
                    mp[y][x]=z;
                    is[x]^=1;
                    is[y]^=1;
                }
            }else{
                int x;
                cin>>x;
                if(is[x]){
                    cout<<"Girls win!\n";
                }else{
                    cout<<"Boys win!\n";
                }
            }
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}