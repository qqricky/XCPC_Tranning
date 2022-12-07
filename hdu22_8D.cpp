#include<bits/stdc++.h>
#define next Next
using namespace std;
typedef long long ll;
const int N = 5e5;
int head[N+5],next[2*N+5],ver[2*N+5],tot;
int f[N+5][5];
void init(int n){
	tot = 1;
	for(int i = 0;i <= n;++i) head[i] = f[i][0] = f[i][2] = 0;
	for(int i = 0;i <= n;++i) f[i][1] = 1;
}
void add(int x,int y){
	ver[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
}
void dfs(int x,int pre){
	int y;
    int sum=0;
	for(int i = head[x];i;i=next[i]){
		y = ver[i];
		if(y==pre) continue;
		dfs(y,x);
		f[x][0] += max(f[y][0],max(f[y][1],f[y][2]));
        sum+=f[y][0];
		f[x][1] += f[y][0];
		// f[x][2] = max(f[x][2],f[y][1]+1);
	}
    for(int i = head[x];i;i=next[i]){
		y = ver[i];
		if(y==pre) continue;
		f[x][2] = max(f[x][2],f[y][1]+1+sum-f[y][0]);
	}
}
void solve(){
	int n;scanf("%d",&n);
	init(n);
	int x,y;
	for(int i = 1;i < n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,-1);
	int ans = max(f[1][0],max(f[1][1],f[1][2]));
	printf("%d\n",ans);
}
int main(){
	int T;cin >> T;
	while(T--) solve();
	return 0;
}