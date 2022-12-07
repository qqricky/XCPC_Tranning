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
int f[500];
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x<y)f[x]=y;
    else f[y]=x;
}
bool vis[110];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        for(int i=1;i<=2*n;i++){
            f[i]=i;
        }
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            int x;
            while(1){
                cin>>x;
                if(x==0)break;
                vis[x]=1;
            }
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(!vis[j]){
                    merge(i*2,j*2-1);
                    merge(i*2-1,j*2);
                }
            }
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(getfa(i*2)==getfa(i*2-1)){
                flag=0;
                break;
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
        // cout.flush();
    }
    // cout.flush();
    // system("pause");
    return 0;
}