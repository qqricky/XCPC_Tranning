#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*f;
}
int n,m;
ll cc[N]={};
ll sub[N]={};
int to[N];
ll ask(int x){
    ll ans=0;
    for(;x;x-=(x&-x))ans+=cc[x];
    return ans;
}
void add(int x,int y){
    for(;x<=N;x+=(x&-x)){
        cc[x]+=y;
    }
}
struct node{
    int a,b;
    int c=0;
}nd[N];
bool cmp(node x,node y)
{
    if(x.b==y.b)return x.c<y.c;
    return x.b<y.b;
}
void cdq(int l,int r)
{
    if(l==r)return ;
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(nd+l,nd+mid+1,cmp);
    sort(nd+mid+1,nd+r+1,cmp);
    int t1=mid;
    int t2=r; 
    for(int i=l;i<=r;i++){
        if(t1>=l&&nd[t1].b>nd[t2].b||t2<mid+1){
            add(nd[t1].c,1);
            t1--;
        }
        else{
            sub[nd[t2].c]+=ask(m+1)-ask(nd[t2].c);
            t2--;
        }
    }
    //cout<<l<<' '<<r<<"   "<<t1<<' '<<t2<<endl;
    for(int i=l;i<=mid;i++){
        add(nd[i].c,-1);
    }
    t1=l,t2=mid+1; 
    for(int i=l;i<=r;i++){
        if(t2<=r&&nd[t1].b>nd[t2].b||t1>mid){
            add(nd[t2].c,1);
            t2++;
        }
        else{
            sub[nd[t1].c]+=ask(m+1)-ask(nd[t1].c);
            t1++;
        }
    }
    for(int i=mid+1;i<=r;i++){
        add(nd[i].c,-1);
    }
}
ll calc(){
    ll ret=0;
    for(int i=n;i>=1;i--){
        ret+=ask(nd[i].b);
        add(nd[i].b,1);
    }
    for(int i=1;i<=n;i++)add(nd[i].b,-1);
    return ret;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>nd[i].b;
        nd[i].a=i;
        to[nd[i].b]=i;
    }
    int val;
    for(int i=1;i<=m;i++){
        cin>>val;
        nd[to[val]].c=i;
    }
    for(int i=1;i<=n;i++){
        if(!nd[i].c){
            nd[i].c=m+1;
        }
    }
    ll ans=calc();
    cdq(1,n);
    sub[0]=0;
    //for(int i=1;i<=m;i++)cout<<i<<" sub : "<<sub[i]<<endl;
    for(int i=1;i<=m;i++){
        cout<<ans<<'\n';
        ans-=sub[i];
    }
    cout.flush();
    //system("pause");
    return 0;
}