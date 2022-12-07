
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll n,c,t;
bool check(ll x){
	ll now =0,C=c;
	for(int i = 1;i <= n;++i){
		now += a[i];
		if(now>t*x){
			--C;
			if(C<=0) return 0;
			now = a[i];
		}
		if(now>t*x) return 0;
	}
	return 1;
}
int main(){cin >> n >> c >> t;
	for(int i = 1;i <= n;++i) scanf("%lld",a+i);
	ll l=0,r=1e5,mid;
	while(r-l>1){
		mid = l+r>>1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%lld\n",r);
    system("pause");
	return 0;
}