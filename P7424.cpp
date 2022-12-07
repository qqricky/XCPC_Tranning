#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,m;
int t[N];
int ask(int p){
    int ans=0;
    while(p){
        ans+=t[p];
        p-=(p&-p);
    }
    return ans;
}
void add(int p,int x){
    while(p<=2e5){
        t[p]+=x;
        p+=(p&-p);
    }
}
struct node
{
    int tp,l,r,s;
}q[N*2],q1[N*2],q2[N*2];
int ans[N];
int tot=0;
void solve(int l,int r,int ql,int qr){
    if(ql>qr)return;
    if(l==r){
        for(int i=ql;i<=qr;i++){
            if(q[i].tp==2){
                ans[l]++;
            }
        }
        return;
    }
    int mid=(l+r)>>1;
    int cnt1=0,cnt2=0;
    for(int i=ql;i<=qr;i++){
        if(q[i].tp==1){
            if(q[i].l<=mid){
                add(q[i].r,1);
                q1[++cnt1]=q[i];
            }
            else{
                q2[++cnt2]=q[i];
            }
        }
        else{
            int num=ask(q[i].r)-ask(q[i].l-1);
            if(q[i].s<=num){
                q1[++cnt1]=q[i];
            }
            else{
                q[i].s-=num;
                q2[++cnt2]=q[i];
            }
        }
    }
    for(int i=1;i<=cnt1;i++){
        if(q1[i].tp==1){
            add(q1[i].r,-1);
        }
    }
    for(int i=1;i<=cnt1;i++)q[i+ql-1]=q1[i];
    for(int i=1;i<=cnt2;i++)q[i+cnt1+ql-1]=q2[i];
    solve(l,mid,ql,cnt1+ql-1);
    solve(mid+1,r,cnt1+ql,qr);
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>q[m+i].l>>q[m+i].r>>q[m+i].s;
        q[m+i].tp=2;
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].r;
        q[i].tp=1;
        q[i].l=i;
    }
    solve(1,m+1,1,n+m);
    for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}