#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int cs = 50;
vector<int> e[N];
double a[N],b[N];
void solve(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i) scanf("%lf",a+i);
	for(int i = 1;i <= n;++i) e[i].clear();
	for(int i = 1;i <= m;++i){
		int u,v;scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int t = 1;t < cs/2;++t){
		for(int i = 1;i <= n;++i){
			int cnt=1;
			double sum=a[i];
			for(auto j:e[i]){
				cnt++;
				sum += a[j];
			}
			b[i] = sum/cnt;
		}
		for(int i = 1;i <= n;++i) a[i] = b[i];
	}
	for(int i = 1;i <= n;++i) printf("%.6lf\n",a[i]);
}
int main(){
	int T;cin >> T;
	while(T--){
		solve();
	}
	return 0;
}