#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll mod;
int Rrand(){
	int ans = 0;
	ans = (int) (((double)rand() / RAND_MAX)*100000);
	return ans;
}
ll qpow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
ll a[N+5];
int solve(){
	ll n;
	scanf("%lld%lld",&n,&mod);
	for(int i = 1;i <= n;++i) scanf("%lld",a+i);
	int T=max(n/500,1ll*350);
	int ans = -1;
	int cnt=0;
	while(T--){
		int x = (int) (((double)rand() / RAND_MAX)*200000)%n+1;
		int y = x+2;
		++cnt;
		if(cnt>180){
			y = x+1;
		}
		if(y>n) continue;
		ll q = a[y]*qpow(a[x],mod-2)%mod;
		ll rq = qpow(q,mod-2);
		int len = 2;
		ll ne = a[x]*rq%mod;
		for(int i = x-1;i >= 1;--i){
			if(a[i]==ne){
				++len;
				ne = a[i]*rq%mod;
				continue;
			}
		}
		ne = a[y]*q%mod;
		for(int i = y+1;i <= n;++i){
			if(a[i]==ne){
				++len;
				ne = a[i]*q%mod;
				continue;
			}
		}
		if(len>=(n+1)/2){
			ans = max(len,ans);
			if(ans==n||y-x==1) break;
		}
	}
	return ans;
}
int main(){
	int T;cin >> T;
	while(T--){
		int ans = solve();
		printf("%d\n",ans);
	}
	return 0;
}