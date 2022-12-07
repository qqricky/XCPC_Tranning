#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll qpow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1; 
	}
	return ans;
}
ll f[20];
ll g[20][200];
unordered_map<string,int>num;
int cnt[10];
ll dp(ll r,ll s){
	if(r==0){
		g[r][s] = 0;
		return 0;
	}
	if(g[r][s]!=-1) return g[r][s];
	if(3*r>s){
		g[r][s] = 0;
		return 0;
	}
	ll ans;
	if(r==1) ans = (s-3*r)*dp(r,s-1)%mod;
	else ans = 3*r*dp(r-2,s-1)%mod+(s-3*r)*dp(r,s-1)%mod;
	ans = 1+ans*qpow(s,mod-2)%mod;
	g[r][s] = ans;
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	for(int i = 0;i <= 13;++i) for(int j = 0;j <= 200;++j) g[i][j]=-1;
	int s = 34*4-13;
	for(int i = 0;i <= 13;++i) f[i] = dp(i,s);
	int ca=0;
	int T;cin >> T;
	while(T--){
		++ca;
		string str;
        cin>>str;
        int n=str.length();
        str=' '+str;
        memset(cnt,0,sizeof(cnt));
        num.clear();
        set<string>st;
        for(int i=1;i<=n;i+=2){
            string c=str.substr(i,2);
            num[c]++;
            st.insert(c);
            // cout<<c<<' '<<num[c]<<endl;
        }
        for(auto c:st){
            cnt[num[c]]++;
        }
        ll sum = cnt[1];
        cout<<"Case #"<<ca<<": "<<f[sum]<<'\n';
        // printf("Case #%d: %lld\n",ca,f[sum]);
	}
	return 0;
}