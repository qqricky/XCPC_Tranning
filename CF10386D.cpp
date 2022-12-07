#pragma GCC optimise(2)
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 5000+5;
const ll B = 233; 
char s[N];
int n;
ll h[N],f[N],p[N];
unordered_map<ll,ll> mp;
inline ll get(int l,int r){
	return (h[r]-h[l-1]*p[r-l+1]);
}
void solve(){
	ll ans =0;
	for(int i = 0;i <= n;++i) f[i]=0;
	for(int i = 1;i <= n;++i){
		h[i] = (h[i-1]*B+s[i]);
	} 
	ll t1,t2,t,pre;
	for(int i = 2;2*i < n;++i){
		for(int j = 1;j+2*i-3 <= n;++j){
			t1 = get(j,j+i-2);
			t2 = get(j+i-1,j+2*i-3);
			//cout << t1 << ' ' << t2 << endl;
			if(t1==t2) f[j+i-2]++;
		}
		mp.clear();
		for(int j = 1;j <= n;++j){
			t = get(j,j+i-1);
			ans += mp[t];
			if(i<j){
				pre = get(j-i,j-1);
				mp[pre]+=f[j-i-1];
			}
		}
	}
	printf("%lld\n",ans);
    cout.flush();
}
int main(){
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
	p[0] = 1;
	for(int i = 1;i < N-1;++i) p[i] = p[i-1]*B;
	int T;cin >> T;
	while(T--){
		scanf("%s",s+1);
		n = strlen(s+1);
		solve();
	}
    cout<<fixed<<setprecision(6)<<clock()/CLOCKS_PER_SEC<<endl;
    system("pause");
	return 0;
}