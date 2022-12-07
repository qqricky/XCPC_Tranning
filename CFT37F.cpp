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
ll a[N],b[N];
ll sum1=0;
ll sum2=0;
int n;
int tot=0;
bool vis[N]={};
bool isodd[N]={};
struct node
{
    ll x,id;
}nd[N],ld[N],rd[N];
int to[N];
void dfs(int l,int r,bool de,int lev){
    if(l>r)return;
    //cout<<l<<' '<<r<<' '<<de<<' '<<lev<<endl;
    if(lev==0){
        if(de){
            vis[nd[l].id]=1;
        }
        return ;
    }
    int cnt1=0,cnt2=0;
    int j=to[lev];
    for(int i=l;i<=r;i++){
        if(((nd[i].x)>>j)&1){
            rd[++cnt2]=nd[i];
        }
        else ld[++cnt1]=nd[i];
    }
    for(int i=l;i<=cnt1;i++)nd[i+l-1]=ld[i];
    for(int i=1;i<=cnt2;i++)nd[i+cnt1+l-1]=rd[i];
    int num1=cnt1,num2=cnt2;
    int val=cnt2&1;
    if(val==isodd[lev]){
        if(de){
            dfs(l,cnt1+l-1,1,lev-1);
            dfs(cnt1+1,r,0,lev-1);
        }
        else{
            dfs(l,cnt1+l-1,0,lev-1);
            dfs(cnt1+1,r,0,lev-1);
        }
    }
    else{
        if(de){
            dfs(l,cnt1+l-1,0,lev-1);
            dfs(cnt1+1,r,1,lev-1);
        }
        else{
            if(cnt1==0){

            }
            else if(cnt2==0){
                
            }
            else{
                dfs(l,cnt1+l-1,1,lev-1);
                dfs(cnt1+1,r,1,lev-1);
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
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1^=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        nd[i].x=b[i]^a[i];
        nd[i].id=i;
        sum2^=b[i];
    }
    for(int j=60;j>=0;j--){
        int x=((sum1>>j)&1);
        int y=((sum2>>j)&1);
        if(x^y)continue;
        tot++;
    }
    int tmp=tot;
    for(int j=60;j>=0;j--){
        int x=((sum1>>j)&1);
        int y=((sum2>>j)&1);
        if(x^y)continue;
        if(x+y==0){
            to[tmp]=j;
            isodd[tmp]=1;
        }
        else{
            to[tmp]=j;
            isodd[tmp]=0;
        }
        tmp--;
    }
    dfs(1,n,0,tot);
    int num=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            num++;
            sum1^=nd[i].x;
            sum2^=nd[i].x;
        }
    }
    cout<<sum1+sum2<<' ';
    cout<<num<<'\n';
    for(int i=1;i<=n;i++){
        if(!vis[i])cout<<i<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}