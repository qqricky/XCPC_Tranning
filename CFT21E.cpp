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
int f[1070][1070][2];
int g[1070][1070][2]={};
int mp[1070][1070][2]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    memset(f,0x3f,sizeof(f));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            while(tmp%2==0){
                mp[i][j][0]++;
                tmp/=2;
            }
            while(tmp%5==0){
                mp[i][j][1]++;
                tmp/=5;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-1>0){
                f[i][j][1]=f[i-1][j][1];
                g[i][j][0]=mp[i][j][0]+g[i-1][j][0];
                g[i][j][1]=mp[i][j][1]+g[i-1][j][1];
                int tmp=min(g[i][j][0],g[i][j][1]);
                g[i][j][0]-=tmp;
                g[i][j][1]-=tmp;
                f[i][j][1]+=tmp;

                f[i][j][0]=f[i-1][j][0];
                g[i][j][0]=mp[i][j][0]+g[i-1][j][0];
                g[i][j][1]=mp[i][j][1]+g[i-1][j][1];
                int tmp=min(g[i][j][0],g[i][j][1]);
                g[i][j][0]-=tmp;
                g[i][j][1]-=tmp;
                f[i][j][0]+=tmp;
            }
            if(j-1>0){
                f[i][j][0]=f[i][j-1][0];
                f[i][j][0]=f[i][j-1][0];
                f[i][j][0]=f[i][j-1][0];
                f[i][j][0]=f[i][j-1][0];
            }
        }
    }
    cout.flush();
    system("pause");
    return 0;
}