#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optmise(2);
const int N=505;
const int NN=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n,m;
int d[505][505]={};
int ans[NN];
int ncnt=0;
inline void add(int x,int y,int z)
{
    int kk=y;
    for(;x<=505;x+=x&-x){
        for(kk=y;kk<=505;kk+=kk&-kk){
            d[x][kk]+=z;
        }
    }
}
inline int ask(int x,int y){
    int ans=0;
    int kk=y;
    for(;x;x-=x&-x){
        for(kk=y;kk;kk-=kk&-kk){
            ans+=d[x][kk];
            //cout<<x<<' '<<kk<<endl;
        }
    }
    return ans; 
}
struct query
{
    int x,y,a,b,k;
    int rk;
}q[60070],q1[60070],q2[60070];
struct node
{
    int x,y,v;
}mp[3*NN];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
void solve(int l,int r,int ql,int qr)
{
    if(qr<ql)return;
    if(l==r){
        for(int i=ql;i<=qr;i++){
            ans[q[i].rk]=mp[l].v;
        }
        return;
    }
    int mid=(l+r)>>1;
    for(int i=l;i<=mid;i++){
        add(mp[i].x,mp[i].y,1);
    }
    int cnt1=0,cnt2=0;
    for(int i=ql;i<=qr;i++){
        int ck=ask(q[i].a,q[i].b)-ask(q[i].x-1,q[i].b)-ask(q[i].a,q[i].y-1)+ask(q[i].x-1,q[i].y-1);
        //cout<<"ask  : "<<q[i].x<<' '<<q[i].y<<' '<<q[i].a<<' '<<q[i].b<<' '<<ck<<"  to  "<<mp[mid].v<<endl;
        if(ck<q[i].k){
            //cout<<"sowhat "<<ck<<' '<<q[i].k<<' '<<q[i].rk<<endl;
            q[i].k-=ck;
            q2[++cnt2]=q[i];
        }
        else{
            q1[++cnt1]=q[i];
            //cout<<"what  "<<q[i].rk<<endl;
        }
    }
    for(int i=l;i<=mid;i++){
        add(mp[i].x,mp[i].y,-1);
    }
    for(int i=1;i<=cnt1;i++){
        q[ql+i-1]=q1[i];
    }
    for(int i=1;i<=cnt2;i++){
        q[ql+cnt1+i-1]=q2[i];
    }
    solve(l,mid,ql,ql+cnt1-1);
    solve(mid+1,r,ql+cnt1,qr);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n);read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int val;
            read(val);
            mp[++ncnt].x=i;
            mp[ncnt].y=j;
            mp[ncnt].v=val;
        }
    }
    sort(mp+1,mp+ncnt+1,cmp);
    mp[0].v=-1;
    mp[ncnt+1].v=INF;
    //cout<<ncnt<<endl; 
    for(int i=1;i<=m;i++){
        read(q[i].x);
        read(q[i].y);
        read(q[i].a);
        read(q[i].b);
        read(q[i].k);
        q[i].rk=i;
    }
    solve(1,ncnt,1,m);
    for(int i=1;i<=m;i++){
        write(ans[i]);
        putchar('\n');
    }
    //cout.flush();
    //system("pause");
    return 0;
}