#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb(x) push_back(x)
ll tr[4000005][2];
int lazy[4000006];
int nums[4000006];
const ll mod=998244353;
string str;
void push_up(int p){
	tr[p][0]=tr[p<<1][0]+tr[p<<1|1][0];
	tr[p][1]=tr[p<<1][1]+tr[p<<1|1][1];
	nums[p]=nums[p<<1]+nums[p<<1|1];
}
void build(int p,int l,int r){
	if(l==r){
		nums[p]=0;;
		if(str[l-1]=='0')tr[p][0]=l,tr[p][1]=0;
		else tr[p][1]=l,tr[p][0]=0,nums[p]=1;
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	push_up(p);
}

void push_down(int p,int l,int r){
	if(lazy[p]==1){
		lazy[p]=0;
		swap(tr[p<<1][0],tr[p<<1][1]);
		swap(tr[p<<1|1][0],tr[p<<1|1][1]);
		lazy[p<<1]=1-lazy[p<<1];
		lazy[p<<1|1]=1-lazy[p<<1|1];
		int mid=l+r>>1;
		nums[p<<1]=(mid-l+1)-nums[p<<1];
		nums[p<<1|1]=(r-mid)-nums[p<<1|1];
	}
}
void fan(int p,int L,int R,int l,int r){
	if(l>=L&&r<=R){
		lazy[p]=1-lazy[p];
		swap(tr[p][0],tr[p][1]);
		nums[p]=(r-l+1)-nums[p];
		return;
	}
	int mid=l+r>>1;
	push_down(p,l,r);
	if(mid>=R){
		fan(p<<1,L,R,l,mid);
		push_up(p);
		return;
	}
	if(mid<L){
		fan(p<<1|1,L,R,mid+1,r);
		push_up(p);
		return;
	}
	fan(p<<1,L,R,l,mid);
	fan(p<<1|1,L,R,mid+1,r);
	push_up(p);
}
ll find(int p,int L,int R,int l,int r,int op){
	if(l>=L&&r<=R){
		return tr[p][op];
	}
	int mid=l+r>>1;
	push_down(p,l,r);
	if(mid>=R){
		return find(p<<1,L,R,l,mid,op);; 
	}
	if(mid<L){
		return find(p<<1|1,L,R,mid+1,r,op);
	}
	ll tmp=0;
	tmp+=find(p<<1,L,R,l,mid,op);
	tmp+=find(p<<1|1,L,R,mid+1,r,op);
	return tmp;
}
int findnum(){
	return nums[1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	while(cin>>n>>q){
		int jjj;
		for(jjj=0;jjj<=2*n+10;jjj++)lazy[jjj]=0;
		cin>>str;
		build(1,1,n);
		while(q--){
			int l,r;
			cin>>l>>r;
			fan(1,l,r,1,n);
			int cnt=findnum();
			if(cnt==0){
				cout<<0<<'\n';
				continue;
			}
			ll ans=0;
			ll he=0;
			if(cnt!=n)he+=find(1,cnt+1,n,1,n,1)*2ll;
			if(cnt!=1)
			he-=find(0,1,cnt-1,1,n,0)*2ll;
			if(find(1,cnt,cnt,1,n,1)==0)he-=cnt;
			else he+=cnt;
			cout<<"-------------"<<he%mod<<endl;
		}
		//cout.flush();
	}
}