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
int dis[10][10];
void floyd(){
    for(int k=1;k<=7;k++){
        for(int i=1;i<=7;i++){
            for(int j=1;j<=7;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=7;i++){
        dis[i][i]=0;
    }
    dis[1][2]=dis[2][1]=1;
    dis[1][3]=dis[3][1]=1;
    dis[3][4]=dis[4][3]=1;
    dis[2][4]=dis[4][2]=1;
    dis[4][5]=dis[5][4]=1;
    dis[4][6]=dis[6][4]=1;
    dis[5][7]=dis[7][5]=1;
    dis[6][7]=dis[7][6]=1;
    floyd();
    while(t--){
        int a[3][3];
        for(int i=1;i<=2;i++){
            cin>>a[i][0]>>a[i][1];
        }
        int ans=INF;
        ans=min(ans,dis[a[1][1]][a[2][1]]+dis[a[1][0]][a[2][0]]);
        ans=min(ans,dis[a[1][1]][a[2][0]]+dis[a[1][0]][a[2][1]]);
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}