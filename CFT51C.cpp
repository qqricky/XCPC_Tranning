#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 5003;
ll d[2][N][61][61][2],m,len[2],af[N],ans[2];
char L[2][N];
void jian(){
	for(int i = len[0]-1;i >= 0;--i){
		if(L[0][i]!='0'){
			L[0][i]--;
			return;
		}
		L[0][i] = '9';
	}
}
int f(int op,int dig){
	if(dig==len[op]){
		for(int i = 0;i <= 9;++i){
		 for(int j = 0;j < m;++j){
		 	for(int k = 0;k < m;++k){
		 		ll x,y;
		 		x = (j+i)%m,y = (k+i*af[dig]%m)%m;
		 		f(op,dig+1);
		 		if(i==L[op][dig]-'0') d[op][dig][x][y][1] += 1;
		 		d[op][dig][x][y][0] = (d[op][dig][x][y][0]+1);
			 }
		 }
	}
	return 0;
	}
	ll x,y;
	for(int i = 0;i <= 9;++i){
		 for(int j = 0;j < m;++j){
		 	for(int k = 0;k < m;++k){
		 		x = (j+i)%m,y = (k+i*af[dig]%m)%m;
		 		f(op,dig+1);
		 		if(i==L[op][dig]-'0') d[op][dig][x][y][1] += d[op][dig+1][j][k][1];
		 		d[op][dig][x][y][0] = (d[op][dig][x][y][0]+d[op][dig+1][j][k][0]);
			 }
		 }
	}
	return 1;
}
int main(){
	af[0] = 1;
	int T;cin >> T;
	while(T--){
		scanf("%s%s",L[0],L[1]);
		scanf("%lld",&m);
		len[0] = strlen(L[0]);
		len[1] = strlen(L[1]);
		for(int i = 1;i < N;++i) af[i] = af[i-1]*10%m;
		jian();
		for(int i = 0;i < len[0]/2;++i) swap(L[0][i],L[0][len[0]-i-1]);
		for(int i = 0;i < len[1]/2;++i) swap(L[1][i],L[1][len[1]-i-1]);
		f(0,0);
		f(1,0);
		for(int i=0;i<m;i++)for(int j=0;j<m;j++)ans[1]+=d[1][len[1]-1][i][j][0]+d[1][len[1]-1][i][j][1],ans[0]+=d[0][len[1]-1][i][j][0]+d[0][len[1]-1][i][j][1];
		ll res = ans[1]-ans[0];
		printf("%lld\n",res);
	}
	return 0;
}