#include<bits/stdc++.h>
#define deb (cout << "deb" << endl)
using namespace std;
typedef long long ll;
ll mod,f[2030][2030],A[2030],g[2030],c[2030][2030];
ll C(ll n,ll m){
	return c[n][m];
}
ll gun(ll n){
	if(n>=0&&n<=2) return g[n] = 1;
	if(g[n]>0) return g[n];
	for(ll i = 0;i <= n-2;++i){
		g[n] = (g[n]+gun(i+1)*gun(n-i-2)%mod*C(n-2,i)%mod)%mod;
	}
	return g[n];
}
ll fun(ll n,ll r){
	if(r>n){
		f[n][r] = -1;
		return 0;
	}
	if(n==r){
		if(r==1) f[n][r] = 1;
		else f[n][r] = -1;
		//cout << n << ' ' << r << endl;
		return max(f[n][r],0ll);
	}
	if(f[n][r]!=0){
		return max(f[n][r],0ll);
	}
	for(int i = 1;i <= r;++i){
		for(int j = i;j <= n-r+i-1;++j){
			f[n][r] = (f[n][r]+fun(j,i)*g[n-j-1]%mod*C(r-1,r-i)%mod*C(n-r-1,j-i)%mod)%mod;
			//cout << n << ' ' << r << ' '<<f[n][r] << endl;
		}
	}
	return f[n][r];
	
}
int main(){
	ll r,n;cin >> r >> n >> mod;
	A[0] = 1;
	c[0][0] = 1;
	c[1][0] = c[1][1] = 1;
	for(int i = 1;i <= 2021;++i) A[i] = A[i-1]*i%mod;
	for(int i = 2;i <= 2021;++i){
		c[i][0] = 1;
		for(int j = 1;j <= i;++j){
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
			//cout << c[i][j] << ' ' << i << ' ' << j << endl;
		}
	}
	gun(n);
	cout << fun(n,r)%mod;
	return 0;
}