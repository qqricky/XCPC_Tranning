#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+5;
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
ll dd[N]={};
ll gg[N]={};
int n,m;
inline ll ask(int x){
    ll res = 0;
	for(int k = x; k; k -= k & -k)
		res += dd[k];
	return res;
}
inline void add(int p, int l, int typ) {
	for(int k = p; k < N; k += k & -k) {
		dd[k] += 1ll * p * l * typ;
		gg[k] += l * typ;
	}
}
inline ll askk(int x){
    ll res = 0;
	for(int k = x; k; k -= k & -k)
		res += gg[k];
	return res;
}
struct juice
{
    ll d,p,l;
}q[2*N];
struct boy
{
    ll g,l,pos;
}qb[N],q1[N],q2[N];
bool cmp(juice a,juice b)
{
    // if(a.d==b.d){
    //     return a.p<b.p;
    // }
    return a.d<b.d;
}
inline bool ck(int pos)
{
    int l=0,r=N-1;
    //cout<<pos<<endl;
    //if(askk(r)<q[pos].l)return 0;
    while(l<r){
        int mid=(l+r)>>1;
        //cout<<mid<<endl;
        if(askk(mid)>=qb[pos].l){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    //cout<<"pos : "<<pos<<' '<<l<<" askkL : "<<askk(l)<<" as  "<<ask(l)<<endl;
    //cout<<"ggggg   "<<qb[pos].g<<endl;
    //cout<<"1  :"<<ask(1)<<"  2  :"<<ask(2)<<"  3  :"<<ask(3)<<endl;
    ll tmpp=ask(l);
    ll tmpl=askk(l);
    if(tmpl>=qb[pos].l &&tmpp-(tmpl-qb[pos].l)*l<=qb[pos].g){
        return 1;
    }
    return 0;
}
ll ans[N];
void solve(int l,int r,int  ql,int qr)
{
    //cout<<"wwwwwwwww "<<l<<' '<<r<<"   :   "<<ql<<' '<<qr<<endl;
    //if(qr<ql)return;
    if(l==r){
        //cout<<l<<' '<<d[l]<<endl;
        for(int i=ql;i<=qr;i++){
            ans[qb[i].pos]=q[l].d;
            //cout<<"anss : "<<qb[i].pos<<' '<<l<<' '<<q[l].d<<endl;
        }
        //cout<<"akldfjlkajk "<<l<<' '<<P[l]<<' '<<L[l]<<endl;
        add(q[l].p,q[l].l,1);
        return;
    }
    int mid=(l+r+1)>>1;
    int cnt1=0,cnt2=0;
    for(int i=mid;i<=r;i++){
        add(q[i].p,q[i].l,1);
    }
    for(int i=ql;i<=qr;i++){
        int lll=0,rr=N-1;
        while(lll<rr){
            int mid=(lll+rr)>>1;
            //cout<<mid<<endl;
            if(askk(mid)>=qb[i].l){
                rr=mid;
            }
            else{
                lll=mid+1;
            }
        }
        //cout<<"ggggg   "<<qb[pos].g<<endl;
        //cout<<"1  :"<<ask(1)<<"  2  :"<<ask(2)<<"  3  :"<<ask(3)<<endl;
        ll tmpp=ask(lll);
        ll tmpl=askk(lll);
        //cout<<qb[i].pos<<"  :  "<<lll<<endl;
        if(tmpl>=qb[i].l &&tmpp-(tmpl-qb[i].l)*lll<=qb[i].g){
            q2[++cnt2]=qb[i];
            //cout<<qb[i].pos<<endl;
        }
        else{
            q1[++cnt1]=qb[i];
        }
    }
    for(int i=mid;i<=r;i++){
        add(q[i].p,q[i].l,-1);
    }
    //cout<<cnt2<<endl;
    for(int i=1;i<=cnt1;i++)qb[ql+i-1]=q1[i];
    for(int i=1;i<=cnt2;i++)qb[ql+cnt1+i-1]=q2[i];
    solve(mid,r,ql+cnt1,qr);
    solve(l,mid-1,ql,ql+cnt1-1);
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
        q[i].d=read();
        q[i].p=read();
        q[i].l=read();
    }
    q[0].d=-1;
    q[0].p=1;
    q[0].l=1;
    sort(q,q+n+1,cmp);
    for(int i=1;i<=m;i++){
        cin>>qb[i].g;
        cin>>qb[i].l;
        qb[i].pos=i;
    }
    solve(1,n+1,1,m);
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }
    //cout.flush();
    //system("pause");
    return 0;
}