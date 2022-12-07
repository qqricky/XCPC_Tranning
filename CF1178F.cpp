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

ll dp[505][505]={};
int a[505];
int n,m;
const ll mod=998244353;
ll dfs(int l,int r){
	if(dp[l][r])	return dp[l][r];
	if(l>=r)	return 1;
	int p=l;
	for(int i=l;i<=r;i++){
        if(a[i]<a[p]){
            p=i;
        }
    }
	ll ans1=0,ans2=0;
    for(int i=l;i<=p;i++){
		ans1=(ans1+dfs(l,i-1)*dfs(i,p-1)%mod)%mod;
	}
	for(int i=p;i<=r;i++){
		ans2=(ans2+dfs(p+1,i)*dfs(i+1,r)%mod)%mod;
	}
	ll ans=ans1*ans2%mod;
	dp[l][r]=ans;
	return ans;
}
int main(){
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dfs(1,n);
	cout.flush();
    // system("pause");
    return 0;
}
