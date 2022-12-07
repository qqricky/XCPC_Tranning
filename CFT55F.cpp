#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb(a) push_back(a)
int tr[1000006];
int val[1000006];
int cnt[1000006];
vector<int>g[1000006];ll tar;
void dfs(int u,int last){
	tr[u]=val[u];
	if(g[u].size()==1&&last!=-1){
		return;
	}
	int i;
	for(i=0;i<g[u].size();i++){
		if(g[u][i]==last)continue;
		dfs(g[u][i],u);
		tr[u]+=tr[g[u][i]];
	}
}
void dfs1(int u,int last){
	if(g[u].size()==1&&last!=-1){
		if(tar*(cnt[u]+1)==tr[u]){
		cnt[u]++;
	}
		return;
	}
	int i;
	for(i=0;i<g[u].size();i++){
		if(g[u][i]==last)continue;
		dfs1(g[u][i],u);
		cnt[u]+=cnt[g[u][i]];
	}
	if(tar*(cnt[u]+1)==tr[u]){
		cnt[u]++;
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int sum=0;
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;i++)cin>>val[i],sum+=val[i];
	for(i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	if(sum%3!=0){
		cout<<"NO\n";
	}
	tar=sum/3;
	dfs(1,-1);
	dfs1(1,-1);
	if(cnt[1]<3){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
	}
}
