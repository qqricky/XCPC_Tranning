#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+20;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int read(){
    char ch=getchar();int x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int d[N]={};
int n,m;
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=d[x];
    return ans;
}
void add(int x,int y){
    for(;x<=n;x+=(x&-x))d[x]+=y;
}
struct query
{
    int l,r,k,pos,tp;
}q[N*2],q1[2*N],q2[2*N];
pair<int,int>b[N];
int a[N];
int raw[N];
int ans[N];
int tot=0;
void solve(int l,int r,int ql,int qr)
{
    //cout<<l<<' '<<r<<"   :   "<<ql<<' '<<qr<<endl;
    if(qr<ql)return;
    if(l==r){
        for(int i=ql;i<=qr;i++){
            if(q[i].tp==2){
                ans[q[i].pos]=l;
                //cout<<q[i].pos<<' '<<l<<endl;
            }
        }
        return;
    }
    int mid=(l+r)>>1;
    int cnt1=0,cnt2=0;
    for(int i=ql;i<=qr;i++){
        if(q[i].tp==1){
            if(q[i].l<=mid){
                add(q[i].pos,1);
                q1[++cnt1]=q[i];
            }
            else{
                q2[++cnt2]=q[i];
            }
        }
        else{
            int tt=ask(q[i].r)-ask(q[i].l-1);
            if(q[i].k<=tt){
                q1[++cnt1]=q[i];
            }
            else{
                q[i].k-=tt;
                q2[++cnt2]=q[i];
            }
        }
    }
    for(int i=1;i<=cnt1;i++){
        if(q1[i].tp==2)break;
        add(q1[i].pos,-1);
    }
    for(int i=1;i<=cnt1;i++)q[ql+i-1]=q1[i];
    for(int i=1;i<=cnt2;i++)q[ql+cnt1+i-1]=q2[i];
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
        int tmp;
        read(tmp);
        //cout<<tmp<<endl;
        b[i].first=tmp;
        b[i].second=i;
    }
    sort(b+1,b+n+1);
    int ncnt=0;
    for(int i=1;i<=n;i++){
        if(b[i].first!=b[i-1].first)ncnt++;
        a[b[i].second]=ncnt;
        raw[ncnt]=b[i].first;
    }
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<"       www"<<endl;
        q[++tot]={a[i],-1,-1,i,1};
    }
    int la,ra,ka;
    for(int i=1;i<=m;i++){
        read(la);read(ra);read(ka);
        q[++tot]={la,ra,ka,i,2};
    }
    solve(0,ncnt+1,1,tot);
    for(int i=1;i<=m;i++){
        cout<<raw[ans[i]]<<"\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}