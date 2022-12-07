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
int f[202][202][202]={};
int r[202],g[202],b[202];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=1;i<=x;i++)cin>>r[i];
    for(int i=1;i<=y;i++)cin>>g[i];
    for(int i=1;i<=z;i++)cin>>b[i];
    sort(r+1,r+x+1);
    sort(g+1,g+y+1);
    sort(b+1,b+z+1);
    int ans=0;
    for(int i=x;i>=0;i--){
        for(int j=y;j>=0;j--){
            for(int k=z;k>=0;k--){
                f[i][j][k]=max(f[i+1][j+1][k]+r[i+1]*g[j+1],f[i][j][k]);
                f[i][j][k]=max(f[i+1][j][k+1]+r[i+1]*b[k+1],f[i][j][k]);
                f[i][j][k]=max(f[i][j+1][k+1]+b[k+1]*g[j+1],f[i][j][k]);
                ans=max(ans,f[i][j][k]);
            }
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}