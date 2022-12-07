#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
ll c[15],a[100005],f[100005],C[100005];
int main(){
	ll n,m;cin >> n >> m;
	for(int i = 0;i < n;++i) scanf("%lld",a+i);
	C[0] =f[0] =  1;
	for(int i = 1;i <= m;++i){
		C[i] = C[i-1]*(n+i-1)%mod*qpow(i,mod-2)%mod;
	}
	ll rev = qpow(C[m],mod-2);
	for(int i = 1;i <= m;++i){
		C[i] = C[i-1]*(n+i-2)%mod*qpow(i,mod-2)%mod;
		f[i] = f[i-1]+C[i];
		f[i] %= mod;
	}
	for(int i = 0;i < n;++i){
		ll use1 = 0,use2 = 0,pre = a[i];
		while(use1<=m){
			ll t = 1;
			while(pre/t!=0) t *= 10;
			if(pre!=0)t /= 10;
			int d;
			for(int j = 1;j <= 10;++j)
				if(t*j>pre){
					t = t*j;
					d = j-1;
					break;
				}
			use2 = t-a[i];
			if(use2>m) use2 = m+1;
			c[d] = (c[d]+f[use2-1]-(use1==0?0:f[use1-1])+mod)%mod;
			use1 = use2;
			pre = t;
		}
	}
	for(int i = 1;i <= 9;++i) cout << c[i]*rev%mod << ' '; 
	return 0;
}
