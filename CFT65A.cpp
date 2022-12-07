#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 8e18;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
ll qpow(ll a,ll b,ll lim){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a;
		if(ans>lim) return -1;
		a = a*a;
		b >>= 1;
	}
	//cout << ans << ' ';
	if(ans>lim) return -1ll;
	return ans;
}
int main(){
	ll n,m;cin >> n >> m;
	if(n<=2){
		if(m>=2)
		cout << m-2 << ' '<<m-1 << endl;
		else{
			printf("impossible\n");
		}
		return 0;
	}
	ll lim = 1000;
	for(ll p=1;p<=lim;++p){
		for(ll q=p+1;q<=lim;++q){
			if(gcd(p,q)!=1) continue;
			ll t = (qpow(q,n,mod)-qpow(p,n,mod))/(q-p);
			if(t<=0) continue;
			if(m%t==0){
				printf("%lld %lld\n",q-p,q);
				return 0;
			}
			if(t>m) break;
		}
	}
	//printf("impossible\n");
	
	printf("impossible\n");
	return 0;
}
