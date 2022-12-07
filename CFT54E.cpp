#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e7;
const ll mod=1e9+7;
bool v[N+5];
ll p[N+5],tot,to[N+5];
void init(){
	for(ll i = 1;i<=N;++i) to[i] = i;
	for(ll i = 2;i<=N;++i)
		if(!v[i]){
			v[i] = 1;
			p[tot++] = i;
			for(ll j = 2;i*j<=N;++j){
				v[i*j] = 1;
				while(to[i*j]%(i*i)==0) to[i*j]/=i*i;
			}
		}
}
ll b[N+5],cnt[N+5],tail;
int main(){
	init();
	int n;cin >> n;
	for(int i = 0;i < n;++i){
		scanf("%lld",b+i);
		b[i] = to[b[i]];
	}
	sort(b,b+n);
	b[tail++] = b[0];
	cnt[tail-1]++;
	for(int i = 1;i < n;++i){
		if(b[i]^b[i-1]) b[tail++] = b[i];
		cnt[tail-1]++;
	}
	//for(int i = 0;i < tail;++i) cout << cnt[i] << ' ';
	//cout << endl;
	ll ans = 0;
	for(int i = 0;i < tail;++i){
		for(int j = i+1;j < tail;++j){
			//cout << b[i]*b[j] << ' ' << cnt[i]*cnt[j] << endl;
			if(b[i]*b[j]>N) ans += b[i]*b[j]*cnt[i]*cnt[j]%mod;
			else ans+=to[b[i]*b[j]]*cnt[i]*cnt[j]%mod;
			ans %= mod;
		}
	}
	for(int i = 0;i < tail;++i){
		ans += (cnt[i]*(cnt[i]-1)/2)%mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}