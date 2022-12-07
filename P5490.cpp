#include <bits/stdc++.h>
using namespace std;
#define ll long long
//扫描线模板
const int N=1e5+10;
struct SegmentTree
{
    int l,r;
    ll sum,add;
    #define l(x) tr[x].l
    #define r(x) tr[x].r
    #define sum(x) tr[x].sum
    #define add(x) tr[x].add
}tr[4*N];
void build(int l,int r,int p)
{
    l(p)=l;
    r(p)=r;
    if(l==r)return;
    int mid=(l+r)>>2;
    build(l,mid,p*2);
    build(mid+1,r,p*2+1);
}
void change(int l,int r,int d,int p)
{
    if(l(p)>=l&&r(p)<=r){
        sum(p)+=d*(l(p)-r(p)+1);
        add(p)+=d;
        return;
    }
    spred(p);
    int mid=(l(p)+r(p))>>1;
    if(l<=mid)change(l,mid,d,p*2);
    if(r>mid)change(mid+1,r,d,p*2+1);
    sum(p)=sum(p*2)+sum(p*2+1);
}
void spred(int p)
{
    if(add(p)){
        sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
        sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
        add(p*2)+=add(p);
        add(p*2+1)+=add(p);
        add(p)=0;
    }
}
ll ask(int l,int r,int p)
{
    if(l(p)>=l&&r(p)<=r)return sum(p);
    spred(p);
    ll tmp=0;
    int mid=(l(p)+r(p))>>1;
    if(l<=mid)tmp+=ask(l,r,p*2);
    if(r>mid)tmp+=ask(l,r,p*2+1);
    return tmp;
}
map<int,int>mp;
int to[N];
int x1[N],x2[N],y1[N],y2[N];
int y[2*N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    build(1,n,1);
    for(int i=1;i<=n;i++){
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        y[i*2-1]=y1[i];
        y[i*2]=y2[i];
    }
    sort(y+1,y+2*n+1);
    for(int i=1;i<=2*n;i++){
        mp[y[i]]=i;
        to[i]=y[i];
    }
    return 0;
}