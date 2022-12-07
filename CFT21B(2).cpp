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
    f[0][1][0]=0;
    f[1][0][0]=0;
    f[0][1][1]=0;
    f[1][0][1]=0;
    for(int i=2;i<=n;i++){
        f[0][i][0]=f[0][i][1]=1e4;
        f[i][0][0]=f[i][0][1]=1e4;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i-1][j][1]<f[i][j-1][1]){
                f[i][j][1]=f[i-1][j][1]+mp[i][j][0];
            }
            else if(f[i-1][j][1]>f[i][j-1][1]){
                f[i][j][1]=f[i][j-1][1]+mp[i][j][0];
            }
            else{
                f[i][j][1]=f[i-1][j][1]+mp[i][j][0];
                g[i][j][1]=min(g[i-1][j][1],g[i][j-1][1])+mp[i][j][1];
            }
            if(f[i-1][j][0]<f[i][j-1][0]){
                f[i][j][0]=f[i-1][j][0]+mp[i][j][1];
            }
            else if(f[i-1][j][0]>f[i][j-1][0]){
                f[i][j][0]=f[i][j-1][0]+mp[i][j][1];
            }
            else{
                f[i][j][0]=f[i-1][j][0]+mp[i][j][1];
                g[i][j][0]=min(g[i-1][j][0],g[i][j-1][0])+mp[i][j][0];
            }
        }
    }
    
    cout.flush();
    system("pause");
    return 0;
}