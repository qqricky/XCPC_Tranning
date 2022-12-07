#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=666;
using namespace std;
int read()
{
	char ch=getchar();int x=0,f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node
{
    int x,y;
    node(){}
    node(int x,int y):x(x),y(y){}
    bool operator == (const node &u)const{
        return 1ll*x*u.y-1ll*u.x*y==0;
    }
    bool operator < (const node& u)const{
        return 1ll*x*u.y-1ll*u.x*y<0;
    }
    
}nd[N];
bool cmp(node a,node b)
{
    if(atan2(a.y,a.x)!=atan2(b.y,b.x)){
        return(atan2(a.y,a.x)<atan2(b.y,b.x));
    }
    return a.x<b.x;
}
bool cmp1(node a,node b)
{
    if(atan2(a.y,a.x)!=atan2(b.y,b.x))
        return atan2(a.y,a.x)<atan2(b.y,b.x);
    else return a.x<b.x;
}
int h[N];
int l[N],r[N],L[N],R[N],w[N];
ll dp[N][N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=read();
    while(t--)
    {
        int n=read();
        for(int i=1;i<=n;i++){
            h[i]=read();
            l[i]=read();
            r[i]=read();
            w[i]=read();
            //cin>>h[i]>>l[i]>>r[i]>>w[i];
            nd[2*i-1].x=l[i];
            nd[2*i-1].y=h[i];
            nd[2*i].x=r[i];
            nd[2*i].y=h[i];
        }
        sort(nd+1,nd+2*n+1);
        int tot=unique(nd+1,nd+2*n+1)-nd;
        //memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++){
            L[i]=lower_bound(nd+1,nd+tot+1,node(l[i],h[i]))-nd;
            R[i]=lower_bound(nd+1,nd+tot+1,node(r[i],h[i]))-nd;
        }
        //for(int i=1;i<=tot;i++)dp[i][i]=0;
        for(int len=1;len<=tot;len++){
            for(int i=1;i+len-1<=tot;i++){
                int j=i+len-1;
                dp[i][j]=1e18;
                int ma=-1;
                int now;
                for(int k=1;k<=n;k++){
                    if(L[k]>=i&&R[k]<=j){
                        if(w[k]>ma){
                            ma=w[k];
                            now=k;
                        }
                    }
                }
                if(ma==-1)dp[i][j]=0;
                else{
                    for(int k=L[now];k<=R[now];k++){
                        dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+ma);
                    }
                }
            }
        }
        cout<<dp[1][tot]<<"\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}