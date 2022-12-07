#include<bits/stdc++.h>
#define next nnnnnnnet
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll maxn=3e6+10,mod=998244353;
inline ll qpow(ll x,ll y) {
	ll res = 1;
	while(y) {
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll r[maxn];
inline void ntt(ll *x,ll lim,ll opt) {
	ll i,j,k,m,gn,g,tmp;
	for(i=0; i<lim; ++i) r[i]=(i&1)*(lim>>1)+(r[i>>1] >> 1);
	for(i=0; i<lim; ++i)
		if(i<r[i]) swap(x[i],x[r[i]]);
	for(m=2; m<=lim; m<<=1) {
		k=m>>1;
		gn=qpow(3,(mod-1)/m);
		for(i=0; i<lim; i+=m) {
			g=1;
			for(j=0; j<k; ++j,g=1LL*g*gn%mod) {
				tmp=1LL*x[i+j+k]*g%mod;
				x[i+j+k]=(x[i+j]-tmp+mod)%mod;
				x[i+j]=(x[i+j]+tmp)%mod;
			}
		}
	}
	if(opt==-1) {
		reverse(x+1,x+lim);
		int inv=qpow(lim,mod-2);
		for(i=0; i<lim; ++i) x[i]=1LL*x[i]*inv%mod;
	}
}
ll A[maxn];
ll C(ll n,ll m){
	if(n<m) return 0;
	return A[n]*qpow(A[m],mod-2)%mod*qpow(A[n-m],mod-2)%mod;
}
ll a[maxn],b[maxn];
int main(){
	A[0] = 1;for(int i = 1;i <= maxn-5;++i) A[i] = A[i-1]*i%mod;
	ll n,k,t;cin >> n >> k >> t;
	ll lim = 1,la = 100*C(n+1,2)+n;
	while(lim<=la) lim<<=1;
	a[0] = 1;
	ntt(a,lim,1);
	for(int i = 0;i < k;++i){
		memset(b,0,sizeof(b));
		for(int j = 0;j <= n;++j){
			if(i==0) b[100*C(j+1,2)+j] = qpow(A[j],mod-2);
			else b[100*C(j,2)+j] = qpow(A[j],mod-2);
		}
		ntt(b,lim,1);
		for(int j = 0;j < lim;++j) a[j] = a[j]*b[j]%mod;
	}
	ntt(a,lim,-1);
	cout << a[100*t+n]*A[n]%mod;
	return 0;
} 