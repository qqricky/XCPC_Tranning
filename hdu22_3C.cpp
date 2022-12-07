#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int p1[N],p2[N];
int p[2*N];
int pos1[N],pos2[N];
ll f[2*N][2];
const ll mod=998244353;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p1[i];
            pos1[p1[i]]=i;
        }
        for(int i=1;i<=n;i++){
            cin>>p2[i];
            pos2[p2[i]]=i;
        }
        for(int i=1;i<=2*n;i++){
            cin>>p[i];
        }
        int x=pos1[p[1]];
        int y=pos2[p[1]];
        f[1][0]=f[1][1]=0;
        if(x==1){
            f[1][0]=1;
        }
        if(y==1){
            f[1][1]=1;
        }
        for(int i=2;i<=2*n;i++){
            f[i][0]=0;
            f[i][1]=0;
            int x=pos1[p[i]];
            int y=pos2[p[i]];
            int a=pos1[p[i-1]];
            int b=pos2[p[i-1]];
            if(i-x==b){
                f[i][0]=(f[i][0]+f[i-1][1])%mod;
            }
            if(a+1==x){
                f[i][0]=(f[i][0]+f[i-1][0])%mod;
            }
            if(i-y==a){
                f[i][1]=(f[i][1]+f[i-1][0])%mod;
            }
            if(b+1==y){
                f[i][1]=(f[i][1]+f[i-1][1])%mod;
            }
        }
        cout<<(f[2*n][0]+f[2*n][1])%mod<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}