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
struct segment
{   
    int l,r,w;
    bool operator <(const segment &a){
        if(l==a.l)return r<a.r;
        return l<a.l;
    }
}s[3*N];
int c[10*N];
int c2[10*N];
int a[10*N];
int a2[10*N];
int n,m;
void update(int i,int x)
{
    while(i<=m){
        c[i]=x;
        for(int k=1;k<(i&-i);k<<=1){
            c[i]=min(c[i],c[i-k]);
        }
        i+=(i&-i);
    }
}
int query(int l,int r)
{
    int ans=INF;
    while(l<=r){
        ans=min(ans,a[r]);
        r--;
        for(;r-l>=(r&-r);r-=(r&-r))
        {
            ans=min(ans,c[r]);
        }
    }
    return ans;
}
void update2(int i,int x)
{
    while(i<=m){
        c[i]=x;
        for(int k=1;k<(i&-i);k<<=1){
            c[i]=max(c[i],c[i-k]);
        }
        i+=(i&-i);
    }
}
int query2(int l,int r)
{
    int ans=0;
    while(l<=r){
        ans=max(ans,a[r]);
        r--;
        for(;r-l>=(r&-r);r-=(r&-r))
        {
            ans=max(ans,c[r]);
        }
    }
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    memset(c,0x3f,sizeof(c));
    memset(a,0x3f,sizeof(a));
    memset(c2,0,sizeof(c2));
    memset(a2,0,sizeof(a2));
    cin>>n>>m;
    a[1]=0;
    update(1,0);
    int l,r,w;
    for(int i=1;i<=n;i++){
        cin>>s[i].l>>s[i].r>>s[i].w;
    }
    sort(s+1,s+n+1);
    int ans=INF;
    for(int i=1;i<=n;i++){
        int tmp=query(s[i].l,s[i].r);
        if(s[i].r==m){
            ans=min(ans,tmp+s[i].w);
            continue;
        }
        if(tmp+s[i].w<a[s[i].r]){
            a[s[i].r]=tmp+s[i].w;
            update(s[i].r,tmp+s[i].w);
        }
    }
    for(int i=1;i<=12;i++)cout<<a[i]<<' ';
    cout<<endl;
    cout<<ans<<endl;
    system("pause");
    return 0;
}