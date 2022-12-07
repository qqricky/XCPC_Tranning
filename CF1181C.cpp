#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e3+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char mp[N][N];
int to[N][N];
int go[N][N];
int dp[N][N][10];
int mm[N];
int rmq(int j,int l,int r){
    int k=mm[r-l+1];
    //cout<<'#'<<l<<' '<<r<<' '<<(1<<k)<<endl;
    return min(dp[j][l][k],dp[j][r-(1<<k)+1][k]);
}
int main(){
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    mm[0]=-1;
    for(int i=1;i<=n;i++){
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            to[i][j]=1;
            go[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(mp[i][j]==mp[i][j-1]){
                to[i][j]=to[i][j-1]+1;
            }
        }
        for(int j=1;j<=m;j++){
            dp[j][i][0]=to[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        for(int k=1;k<=mm[n];k++){
            for(int i=1;i+(1<<k)-1<=n;i++){
                dp[j][i][k]=min(dp[j][i][k-1],dp[j][i+(1<<(k-1))][k-1]);
            }
        }
        for(int i=2;i<=n;i++){
            if(mp[i][j]==mp[i-1][j]){
                go[i][j]=go[i-1][j]+1;
            }
        }
    }
    int ans=0;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=m;j++){
            int h=go[i][j];
            int y=i-go[i][j];
            bool flag=1;
            char ch=mp[i][j];
            //cout<<i<<" "<<j<<' '<<h<<endl;
            for(int t=1;t<=2;t++){
                if(t==1&&h!=go[y][j])flag=0;
                if(t==2&&h>go[y][j])flag=0;
                //if(t==2&&mp[y][j]==ch)flag=0;
                y-=go[y][j];
            }
            if(flag){
                ans+=rmq(j,i-h*3+1,i);
                //cout<<i<<' '<<j<<' '<<rmq(j,i-h*3+1,i)<<endl;
            }
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}