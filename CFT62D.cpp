#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
bool v[N+5];
ll p[N+5];
int tot;
char s[300];
ll qpow(ll a,ll b,ll mod){
	if(b<0) return 0;
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return ans;
}
char u(ll x){
	for(int i = 0;i < tot&&p[i]*p[i] <= x;++i){
		if(x%(p[i]*p[i])==0){
			return '0';
		}
		while(x%p[i]==0) x/=p[i];
	}
	return '1';
}
int main(){
    double t1=clock()/CLOCKS_PER_SEC;
	v[1] = 1;
	int pre = -1;
	for(int i = 2;i <= N;++i){
		if(!v[i]){
			p[tot++] = i;
		}
		for(int j = 0;j < tot&&p[j]*i<=N;++j){
			v[i*p[j]] = 1;
			if(i%p[j]==0){
				break;
			}
		}
	}
	
	for(int i = 0;i < 10;++i) scanf("%s",s+20*i);
	
	ll M = 1,R = 0,P=1;
	for(int i = 0;i < 4;++i){
		int r = 0;
		for(int j = 0;j < p[i]*p[i];++j){
			if(s[j]!='0'){
				r--;
				continue;
			}
			bool ok = 1;
			for(int k = j;k < 200;k+=p[i]*p[i]){
				if(s[k]!='0'){
					ok = 0;
					break;
				}
			}
			if(ok){
				r+=p[i]*p[i];
				R = r*qpow(M,p[i]*p[i]-p[i]-1,p[i]*p[i])*M+R*qpow(p[i]*p[i],P-1,M)*p[i]*p[i];
				M = p[i]*p[i]*M;
				R %= M;
				P = P*(p[i]*p[i]-p[i]);
				//cout << p[i]*p[i] << ' ' << R  << ' ' << r << endl;
				break;
			}else{
				--r;
			}
		}
	}
	if(M!=44100){
		printf("-1\n");
		return 0;
	}
	int find = 0;
	for(int k = 0;k*M+R+199<=1000000000;++k){
        if(clock()/CLOCKS_PER_SEC-t1>=0.85){
            break;
        }
		int l = k*M+R;
		bool ok = 1;
		for(int j = 0;j < 200;++j){
			if(u(l+j)!=s[j]){
				ok = 0;
				break;
			}
		}
		if(ok){
			find=1;
			printf("%lld\n",l);
			break;
		}
	}
	if(!find) printf("-1\n");
	return 0;
}