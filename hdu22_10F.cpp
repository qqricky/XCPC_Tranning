#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const ll mod = 998244353;
struct seg{
	int l,r;
}a[N];
bool cmp(seg a1,seg a2){
	return a1.l < a2.l;
}
ll A[3][3];
ll get(int n){
	A[0][0] = 2,A[0][1] = 4;
	A[1][0] = 1,A[1][1] = 0;
	ll B[3][3],C[3][3];
	B[0][0] = 1,B[0][1] = 0;
	B[1][0] = 0,B[1][1] = 1;
	while(n){
		if(n&1){
			for(int i = 0;i < 2;++i)
				for(int j = 0;j < 2;++j){
					C[i][j]=0;
					for(int k = 0;k < 2;++k) C[i][j] = (C[i][j]+A[i][k]*B[k][j]%mod)%mod;
				}
			for(int i = 0;i < 2;++i)
				for(int j = 0;j < 2;++j){
					B[i][j] = C[i][j];
				}
		}
		n>>=1;
		for(int i = 0;i < 2;++i)
			for(int j = 0;j < 2;++j){
				C[i][j]=0;
				for(int k = 0;k < 2;++k) C[i][j] = (C[i][j]+A[i][k]*A[k][j]%mod)%mod;
			}
		for(int i = 0;i < 2;++i)
			for(int j = 0;j < 2;++j){
				A[i][j] = C[i][j];
			}
	}
	for(int i = 0;i < 2;++i)
			for(int j = 0;j < 2;++j){
				A[i][j] = B[i][j];
			}
	return 2*A[0][0]+A[0][1];
}
void solve(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i = 0;i < m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y<x) swap(x,y);
		a[i].l = x+1;
		a[i].r = y+1;
	}
	sort(a,a+m,cmp);
	int x=-1,y=-1;
	for(int i = 0;i < m;++i){
		if(a[i].l>x){
			n -= y-x;
			x = a[i].l;
			y = a[i].r;
		}else y = a[i].r;
	}
	n -= y-x;
	ll ans = get(n-1);
	if(n==2) ans = 5;
	else if(n==1) ans=2;
	printf("%lld\n",ans);
}
int main(){
	int T;cin >> T;
	while(T--){
		//int n;cin >> n;
		//cout << get(n-1) << endl;
		//continue;
		solve(); 
	}
    cout.flush();
    system("pause");
	return 0;
}