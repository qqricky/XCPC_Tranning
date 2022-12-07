#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;cin >> T;
	while(T--){
		ll c,r,s;scanf("%lld%lld%lld",&c,&r,&s);
		ll ans1 = c/s,ans2;
		ll r1 = c%s,r2 = r%s;
		if(r2+r1>s){
			++ans1;
		}
		if(s==1) ans2 = ans1;
		else{
			ll t = c/(s-1)-r;
			if(t<0) ans2 = 0;
			else if(c%(s-1)!=0) ans2 = t+1;
			else ans2 = t;
//			ans2 = (c+r)/s;
//			ans2 -= r;
//			if(ans2<0) ans2 = 0;
//			else if((c+r)%s!=0) ++ans2;
		}
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}