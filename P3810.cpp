#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
const int NN=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*f;
}
int n,k;
int cc[NN]={};
int ans[N]={};
int ask(int x){
    int ans=0;
    for(;x;x-=(x&-x))ans+=cc[x];
    return ans;
}
void add(int x,int y){
    for(;x<=k;x+=(x&-x)){
        cc[x]+=y;
    }
}
struct node{
    int a,b,c;
    int cnt;
    int ans;
}nd[N],ndt[N];
bool cmp(node x,node y)
{
    if(x.a==y.a){
        if(x.b==y.b){
            return x.c<y.c;
        }
        return x.b<y.b;
    }
    return x.a<y.a;
}
bool cmp2(node x,node y)
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
    sort(nd+l,nd+mid+1,cmp2);
    sort(nd+mid+1,nd+r+1,cmp2);
    int t1=l;
    int t2=mid+1;
    for(int i=l;i<=r;i++){
        if(t1<=mid&&nd[t1].b<=nd[t2].b||t2>r){
            add(nd[t1].c,nd[t1].cnt);
            t1++;
        }
        else{
            nd[t2].ans+=ask(nd[t2].c);
            t2++;
        }
    }
    //cout<<l<<' '<<r<<"   "<<t1<<' '<<t2<<endl;
    for(int i=l;i<=mid;i++){
        add(nd[i].c,-nd[i].cnt);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n),read(k);
    for(int i=1;i<=n;i++){
        read(ndt[i].a);
        read(ndt[i].b);
        read(ndt[i].c);
    }
    int cnt=0;
    int n_=0;
    sort(ndt+1,ndt+n+1,cmp);
    for(int i=1;i<=n;i++){
        //cout<<"www "; 
        //cout<<ndt[i].a<<' '<<ndt[i].b<<' '<<ndt[i].c<<endl;
        if(ndt[i].a==ndt[i+1].a&&ndt[i].b==ndt[i+1].b&&ndt[i].c==ndt[i+1].c){
            cnt++;
        }
        else{
            ++n_;
            ++cnt;
            nd[n_]=ndt[i];
            //cout<<"ttt "<<n_<<' '<<cnt<<endl;
            nd[n_].cnt=cnt;
            cnt=0;
        }
    }
    cdq(1,n_);
    for(int i=1;i<=n_;i++){
        ans[nd[i].ans+nd[i].cnt-1]+=nd[i].cnt;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<'\n';
    }
    //cout.flush();
    //system("pause");
    return 0;
}