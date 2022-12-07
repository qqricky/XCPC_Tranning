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
int a[N];
int f[N][10];
int g[N][10];
int h[10][10][10];
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
        int n;
        cin>>n;
        string str;
        cin>>str;
        for(int i=1;i<=n;i++){
            a[i]=(str[i-1]-'0');
        }
        memset(f,0,sizeof(int)*((n+3)*10));
        memset(g,0,sizeof(int)*((n+3)*10));
        //memset(k,0,sizeof(k));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=9;j++){
                f[i][j]=f[i-1][j];
            }
            f[i][a[i]]=f[i-1][a[i]]+1;
            for(int j=1;j<=9;j++){
                f[i][j]=max(f[i][j],f[i][j-1]);
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=0;j<=9;j++){
                g[i][j]=g[i+1][j];
            }
            g[i][a[i]]=g[i+1][a[i]]+1;
            for(int j=1;j<=9;j++){
                f[i][j]=max(g[i][j],g[i][j-1]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int x=a[i];
            for(int j=x;j>=0;j--){
                for(int k=j;k<=x;k++){
                    ans=max(ans,g[i][x]+h[j][x][k]);
                }
            }
            for(int j=9;j>=a[i];j--){
                for(int k=j;k>=a[i];k--){

                }
            }
        }
    }
    cout.flush();
    system("pause");
    return 0;
}