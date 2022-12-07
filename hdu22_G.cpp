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
int f[N];
int sz[N];
int dis[N];
int dia[N];
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x<y){
        f[x]=y;
        sz[x]+=sz[y];
    }
    else if(x>y){
        f[y]=x;
        sz[y]+=sz[x];
    }
}
void getrt(int now){

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
        for(int i=1;i<=n;i++){
            f[i]=i;
            sz[i]=1;
            dia[i]=1;
        }
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            x=getfa(x);
            y=getfa(y);
            if(sz[x]<=sz[y]){
                
            }else{

            }
        }
    }
    cout.flush();
    system("pause");
    return 0;
}