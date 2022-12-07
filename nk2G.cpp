#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
/*
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
*/
struct node
{
    int l,r;
    int len;
    node(){};
    bool operator <(const node& nd)
    {
        if(l==nd.l){
            return r>nd.r;
        }
        return l<nd.l;
    }
};
bool cmp(node a,node b)
{
    return a.len>b.len;
}
int f[5010][5010];
int sum[5010];
node b[5010];
node seg[5010];
vector<node>v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    memset(f,-1,sizeof(f));
    int ed=0;
    for(int i=1;i<=n;i++){
        cin>>seg[i].l>>seg[i].r;
        seg[i].len=seg[i].r-seg[i].l;
    }
    sort(seg+1,seg+n+1);
    int up=INF;
    for(int i=n;i>=1;i--){
        if(seg[i].r>=up){
            v.push_back(seg[i]);
        }
        else{
            b[++ed]=seg[i];
            up=seg[i].r;
        }
    }
    reverse(b+1,b+ed+1);
    f[0][0]=0;
    //for(int i=1;i<=ed;i++)cout<<b[i].l<<' '<<b[i].r<<endl;
    for(int j=1;j<=k;j++){
        priority_queue<pair<int,int> >q;
        for(int i=1;i<=ed;i++){
            while(!q.empty()&&q.top().second<=b[i].l)q.pop();
            if(f[i-1][j-1]!=-1)q.push(make_pair(b[i].r+f[i-1][j-1],b[i].r));
            if(!q.empty())f[i][j]=q.top().first-b[i].l;
        }
    }
    int ans=f[ed][k];
    sort(v.begin(),v.end(),cmp);
    if(!v.empty())
    sum[0]=v[0].len;
    for(int i=1;i<v.size();i++)sum[i]=sum[i-1]+v[i].len;
    for(int i=0;i<v.size();i++){
        //cout<<f[ed][k-i-1]<<endl;
        if(f[ed][k-i-1]!=-1)
        ans=max(ans,f[ed][k-i-1]+sum[i]);
    }
    cout<<max(ans,0)<<endl;
    //system("pause");
    return 0;
}