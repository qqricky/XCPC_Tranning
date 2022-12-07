#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(3)
const int N=8080;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
ll f[N][N];
int dp[N][30];
int mm[N];
int n;
struct node
{
    int x,id,val;
}nd[N],rnd[N];
int rmq(int x,int y){
    if(x>y)return 0;
    int k=mm[y-x+1];
    return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
bool cmp(node a,node b){
    return a.val<b.val;
}
bool cmp2(node a,node b){
    return a.id<b.id;
}
void CDQ(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    CDQ(l,mid);
    for(int i=l;i<=mid;i++){
        nd[i].val=rmq(nd[i].id+1,mid);
    }
    for(int j=mid+1;j<=r;j++){
        nd[j].val=rmq(mid+1,nd[j].id);
    }
    sort(nd+l,nd+mid+1,cmp);
    sort(nd+mid+1,nd+r+1,cmp);
    for(int k=n;k>=1;k--){
        int t1=l;
        int t2=mid+1;
        ll mx=1e16;
        for(int i=l;i<=r;i++){
            if(t1<=mid&&nd[t1].val<=nd[t2].val||t2>r){
                mx=min(mx,f[nd[t1].id][k-1]);
                t1++;
            }else{
                f[nd[t2].id][k]=min(f[nd[t2].id][k],mx+nd[t2].val);
                t2++;
            }
        }
        t1=mid;
        t2=r;
        mx=1e16;
        for(int i=l;i<=r;i++){
            if(t1>=l&&nd[t1].val>=nd[t2].val||t2<mid+1){
                mx=min(mx,f[nd[t1].id][k-1]+nd[t1].val);
                t1--;
            }else{
                f[nd[t2].id][k]=min(f[nd[t2].id][k],mx);
                t2--;
            }
        }
    }
    for(int i=mid+1;i<=r;i++)nd[i]=rnd[i];
    CDQ(mid+1,r);
}

int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    n=read();
    // n=5000;
    for(int i=1;i<=n;i++){
        // nd[i].x=i;
        nd[i].x=read();
        nd[i].id=i;
        rnd[i]=nd[i];
    }
    nd[0].id=0;nd[0].x=0;
    mm[0]=-1;
    for(int i=1;i<=n;i++){
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        dp[i][0]=nd[i].x;
    }
    for(int j=1;j<=mm[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)f[i][j]=1e16;
    }
    f[0][0]=0;
    CDQ(0,n);
    for(int i=1;i<=n;i++){
        printf("%d\n",f[n][i]);
        // cout<<f[n][i]<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}