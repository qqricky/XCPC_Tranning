#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7,maxm=2e5+7,N=1e5+7;
typedef long long int ll;
typedef unsigned long long ull;
struct node {
    int m,d,day,v,at;
    bool operator<(const node& a)const {
        return at<a.at;
    }
} pp[505];
int d[20],n,m,w,a[20],b[20],dp[20][370];
void dfs(int i,int cnt,int now,int v) {
    if(v>d[cnt]) d[cnt]=v;
    if(i==m) return;
    int ans(0);
    if(now>=a[i]) dfs(i+1,cnt+1,now-a[i],v+b[i]);
    dfs(i+1,cnt,now,v);
}
int mon[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1; i<=12; ++i) mon[i]=mon[i]+mon[i-1];
    while(T--) {
        scanf("%d%d%d",&n,&m,&w);
        memset(d,0,sizeof d);
        memset(dp,0,sizeof dp);
        for(int i=1; i<=n; ++i) {
            scanf("%*d-%d-%d %d %d",&pp[i].m,&pp[i].d,&pp[i].day,&pp[i].v);
            if(pp[i].m==2&&pp[i].d==29) {
                --i, --n;
            }
            pp[i].at=mon[pp[i].m-1]+pp[i].d;
        }
        for(int i=0; i<m; ++i) scanf("%d%d",&a[i],&b[i]);
        dfs(0,0,w,0);
        sort(pp+1,pp+1+n);
        while (!d[m]) --m;
        int ans(0);
        for(int i=1; i<=n; ++i)
            for(int k=m; ~k; --k)
                for(int t=pp[i].at; ~t; --t) {
                    if(t>=pp[i].day) dp[k][t]=max(dp[k][t],dp[k][t-pp[i].day]+pp[i].v);//做蛋糕 
                    if(k) dp[k][t]=max(dp[k][t],dp[k-1][t]-d[k-1]+d[k]);//不做第i个人的生日蛋糕
                    ans=max(ans,dp[k][t]);
                }
        printf("%d\n",ans);
        //for(int i=1;i<=m;i++)printf("%d\n",d[i]);
    }
    return 0;;
}