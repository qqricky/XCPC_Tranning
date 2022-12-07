#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int vote[3005]={};
struct  jury{
    int v;
    int c;
    int cur;
}gp[3005];
int p[3003][3003]={};
int num,n,m;
int check(int x)
{
    int tot=0;
    ll cnt=0;
    for(int i=1;i<=x;i++){
        vote[gp[i].v]--;
    }
    for(int i=2;i<=m;i++)
        if(vote[i]>=x+num){
            cnt+=vote[i]-(x+num)+1;
        }
    if(cnt>x)return 0;
    return 1;
    
}
bool cmp(jury x,jury y)
{
    return x.c<y.c;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int g,tmp;
    int maxx=0;
    int pos=0;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x!=1){
            p[x][++p[x][0]]=y;
            gp[++pos].v=x;
            gp[pos].c=y;
            gp[pos].cur=1;
        }
        vote[x]++;
    }
    for(int i=2;i<=m;i++)sort(p[i]+1,p[i]+p[i][0]+1);
    num=vote[1];
    sort(gp+1,gp+pos+1,cmp);
    ll ans=0;
    int r=pos/2+1;
    int l=1;
    int mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    num=num+mid;
    for(int i=2;i<=m;i++)
        if(vote[i]>=num){
            int k=vote[i]-num+1;
            mid-=k;
            for(int j=1;j<=k;j++)ans+=p[i][j];
        }
    cout<<ans;
    //system("pause");
    return 0;
}        