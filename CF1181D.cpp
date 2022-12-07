#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

struct Node
{
    int l,r,sum;
}tree[3000005];
int a[100005],number[100005],root[100005],node_num;
 
void maketree(int l,int r,int &node)
{
    node=++node_num;
    if(l==r)return;
    int mid=(l+r)>>1;
    maketree(l,mid,tree[node].l);
    maketree(mid+1,r,tree[node].r);
}
 
void addtree(int l,int r,int &node,int pre,int pos)
{
    node=++node_num;
    tree[node]=tree[pre];
    tree[node].sum++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)addtree(l,mid,tree[node].l,tree[pre].l,pos);
    else addtree(mid+1,r,tree[node].r,tree[pre].r,pos);
}
 
int query(int l,int r,int node,int pre,int k)
{
    if(l==r)return l;
    int chal=tree[tree[node].l].sum-tree[tree[pre].l].sum;
    int mid=(l+r)>>1;
    if(k<=chal)return query(l,mid,tree[node].l,tree[pre].l,k);
    else return query(mid+1,r,tree[node].r,tree[pre].r,k-chal);
}


struct node
{
    ll id,val;
}nd[N];
bool cmp(node x,node y){
    if(x.val==y.val){
        return x.id<y.id;
    }
    return x.val>y.val;
}
int cnt[N];
vector<pair<ll,int> >v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=m;i++){
        nd[i].id=i;
        nd[i].val=cnt[i];
    }
    sort(nd+1,nd+m+1,cmp);
    for(int i=1;i<=m;i++){
        a[i]=nd[i].id;
        number[i]=nd[i].id;
    }
    sort(number+1,number+1+m);
    int num=unique(number+1,number+1+m)-number-1;
    node_num=0;
    maketree(1,num,root[0]);
    for(int i=1;i<=m;i++){
        int pos=lower_bound(number+1,number+1+num,a[i])-number;
        addtree(1,num,root[i],root[i-1],pos);
    }
    ll nu=0;
    ll tot=0;
    v.push_back(make_pair(0,-1));
    for(int i=m;i>1;i--){
        nu++;
        if(nd[i].val!=nd[i-1].val){
            tot+=nu*(nd[i-1].val-nd[i].val);
            v.push_back(make_pair(tot,i));
        }
    }
    v.push_back(make_pair(1e18+1,1));
    while(q--){
        ll x;
        cin>>x;
        x-=n;
        auto it=lower_bound(v.begin(),v.end(),make_pair(x,0));
        auto itt=it;
        itt--;
        x-=itt->first;
        ll nu=m-it->second+1;
        x--;
        x%=nu;
        x++;
        int pos=query(1,num,root[m],root[it->second-1],x);
        cout<<number[pos]<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}