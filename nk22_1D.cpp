#include<bits/stdc++.h>
#pragma GCC optimise(3)
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 4e4+5;
ll a[64*N],b[64*N],tot;
bool vis[N][64];
ll dfs(ll r,ll now){
	if(now>=tot||r==0) return 1;
	ll ans = 0;
	for(int i = 0;i <= b[now];++i)
		if(i>=(r)/a[i]){
			ans = (ans+dfs(r-i*a[now],now+1))%mod;
		}
	return ans;
}
int main(){
	ll n,m,k;scanf("%lld %lld %lld ",&n,&m,&k);
	for(int i = 0;i < n;++i) scanf("%lld",b+i);
	for(int i = 0;i < k;++i){
		int id,bit;
		scanf("%d%d",&id,&bit);
		vis[id-1][bit]=1;
	}
	int tn=0;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < 63;++j){
			if(vis[i][j]) continue;
			int t = j;
			a[tn++] = b[i];
			while(t--){
				a[tn-1] = a[tn-1]<<1;
				if(a[tn-1]<0||a[tn-1]>m){
					tn--;
					break;
				}
			}
		}
	}
	sort(a,a+tn);
	a[tot++] = a[0];
	b[tot-1] = 1;
	for(int i = 1;i < tn;++i){
		if(a[i]==a[i-1]){
			b[tot-1]++;
			continue;
		}
		a[tot++] = a[i];
		b[tot-1] = 1;
	}
	cout << dfs(m,0);
	return 0;
}