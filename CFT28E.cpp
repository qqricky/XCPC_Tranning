#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,p,f[100005],C[1005][1005];
ll qpow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
int main(){
	cin >> n >> p;
	for(int i = 1;i <= n;++i){
		C[i][0] = 1;
		for(int j = 1;j <= i;++j){
			C[i][j] = C[i][j-1]*(i-j+1)%mod*qpow(j,mod-2)%mod;
		}
	}
	for(int i = 1;i <= n;++i){
		f[i] = 1;
		for(int j = 1;j <= i;++j){
			f[i] = (f[i]+C[i][j]*qpow(p,j)%mod*qpow(100-p,i-j)%mod*qpow(qpow(100,i),mod-2)%mod*f[i-j]%mod)%mod;
		}
		f[i] = f[i]*qpow((1+mod-qpow(100-p,i)*qpow(qpow(100,i),mod-2)%mod),mod-2)%mod;
	}
	cout << f[n]%mod << endl;
	return 0;
}