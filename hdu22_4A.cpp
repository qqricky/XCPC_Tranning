#include<bits/stdc++.h>
#define next NEEE
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[70];
int add(ll x){
	for(int i = 61;i>=0;--i)
		if(x&(1ll<<i)){
			if(a[i]) x ^= a[i];
			else{
				a[i] = x;
				return i;
			}
		}
	return -1;
}
int main(){
	int T;cin >> T;
	while(T--){
		for(int i = 0;i <= 62;++i) a[i] = 0;
		int n;scanf("%d",&n);
		ll x;
		ll ans = 0;
		for(int i = 0;i < n;++i){
			scanf("%lld",&x);
			int id = add(x);
			// if(id!=-1){
			// 	if((ans^a[id])>ans) ans^=a[id];
			// }
		}
        for(int j=61;j>=0;j--){
            if((ans^a[j])>ans) ans^=a[j];
        }
		printf("%lld\n",ans);
	}
    system("pause");
	return 0;
}