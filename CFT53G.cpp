#include <bits/stdc++.h>
#define ll long long
//#pragma GCC optimise(2)
const int N=1070;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int nx,ny;
const int INF=1e9;
double g[N][N];
double lx[N],ly[N];
int linker[N];
double slack[N];
bool visx[N],visy[N];
bool DFS(int x){
    visx[x]=1;
    for(int y=0;y<ny;y++){
        if(visy[y])continue;
        double tmp=lx[x]+ly[y]-g[x][y];
        if(fabs(tmp-0)<1e-6){
            visy[y]=1;
            if(linker[y]==-1||DFS(linker[y])){
                linker[y]=x;
                return 1;
            }
        }
        else if(slack[y]>tmp)slack[y]=tmp;
    }
    return 0;
}
double KM(){
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<nx;i++){
        lx[i]=-INF;
        for(int j=0;j<ny;j++){
            if(g[i][j]>lx[i]){
                lx[i]=g[i][j];
            }
        }
    }
    for(int x=0;x<nx;x++){
        for(int i=0;i<ny;i++){
            slack[i]=INF;
        }
        while(1){
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(DFS(x))break;
            double d=INF;
            for(int i=0;i<ny;i++){
                if(!visy[i]&&d>slack[i]){
                    d=slack[i];
                }
            }
            for(int i=0;i<nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(int i=0;i<ny;i++){
                if(visy[i])ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    double res=0;
    for(int i=0;i<ny;i++){
        if(linker[i]!=-1){
            res+=g[linker[i]][i];
        }
    }
    return res;
}
int anss[N];
int p[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            g[i][j]=log(val);
            //cout<<log(val)<<'\n';
        }
    }
    nx=ny=n;
    double ans=KM();
    //cout<<ans<<endl;
    for(int i=0;i<n;i++){
        anss[linker[i]+1]=i+1;
    }
    for(int i=1;i<=n;i++){
        p[anss[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<p[i]<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}