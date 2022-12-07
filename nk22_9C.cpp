#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimise(2)
using namespace std;
ll shu[100005];
int cnt[100005];
ll dp[8003][8003];
ll add[2][50000];
ll tr[2][50000];
int a[8003];
const ll mod=998244353;
inline ll ad(ll &a,ll b){
    return a+b > mod ? a+b-mod : a+b;
}
void build(int k,int l,int r,int op)   //k表示当前结点的编号，l,r为当前结点所代表的区间
{
    if(l==r)       //当前结点为叶子结点
    {
    	add[op][k]=0;
        tr[op][k]=0;	     //对应区间的最小值为原序列中的对应值
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid,op);        //构造左子树
    build(k*2+1,mid+1,r,op);    //构造右子树
    tr[op][k]=tr[op][k*2]+tr[op][k*2+1];
    tr[op][k]%=mod;
    add[op][k]=0;
}
//区间修改+单点询问
ll get(int k,int l,int r,int p,int op)
{
	//cout<<l<<' '<<r<<' '<<p<<' '<<k<<' '<<op<<' '<<add[op][k]<<endl;
    if(l==r) return add[op][k];
    int mid=l+r>>1;
    if(p<=mid) return (get(k<<1,l,mid,p,op)+add[op][k])%mod;
    else return (get(k<<1|1,mid+1,r,p,op)+add[op][k])%mod;
    //根结点到叶子结点[p,p]的路径上所有点的add之和就是答案
}
//区间[x,y]内所有数加上v
void modify(int k,int l,int r,int x,int y,ll v,int op)
{
	
    if(l>y||r<x) return;
    if(l>=x&&r<=y)
    {
        add[op][k]+=v;
        add[op][k]%=mod;
       // cout<<l<<' '<<r<<' '<<op<<' '<<' '<<k<<' '<<add[op][k]<<endl;
        return;
    }
    int mid=l+r>>1;
    modify(k<<1,l,mid,x,y,v,op);
    modify(k<<1|1,mid+1,r,x,y,v,op);
}
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    int i;
    for(i=1;i<n;i++){
    	cin>>a[i];
	}
	dp[1][0]=1;
	int op=1;
	build(1,1,n,op);
	modify(1,1,n,1,1,1,op);
	ll ans=0;
	for(i=1;i<=n;i++){
		int j;
		op^=1;
		build(1,1,n,op);
		for(j=1;j<=n;j++){
			int h;
			ll fun=get(1,1,n,j,op^1)*ksm(a[j],mod-2)%mod;
			modify(1,1,n,j+1,j+a[j],fun,op);
		}
		//cout<<"123123"<<endl;
		ans+=get(1,1,n,n,op)*get(1,1,n,n,op)%mod;
        ans%=mod;
	}
	ans%=mod;
	cout<<ans<<'\n';
	
	
}