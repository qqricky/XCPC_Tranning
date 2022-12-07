#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int du[100006];
int to[100006];
int dfn[100005];
int dfn1[100005];
int fa[100005];
int duu[100005];
int anss[100005];
int dfx=0;
int die[100005];
vector<int>g[100005];
set<pair<int,int> >st;
void dfs(int a,int last){
	dfn[a]=++dfx;
	to[dfx]=a;
	int i;
	for(i=0;i<g[a].size();i++){
		dfs(g[a][i],a);
	}
	dfn1[a]=dfx;
}
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	int i;
	du[1]=1;
	for(i=2;i<=n;i++){
		cin>>fa[i];
		g[fa[i]].push_back(i);
		duu[fa[i]]++;
		du[i]=du[fa[i]]+1;
		anss[i]=du[i];
	}
	dfs(1,0);
	for(i=1;i<=n;i++){
		if(duu[i]==0){
			st.insert(make_pair(anss[i],i));
		}
	}
	ll ans=0;
	set<pair<int,int> >::iterator it,it1;
	for(i=1;i<=k;i++){
	    it=st.end();
		it--;
		it1=it;
		ans+=(*it).first;
		int v=(*it).second;
		int vv=v;
		//cout<<ans<<' '<<v<<endl;
		v=fa[v];
		die[vv]=1;
		while(v!=0&&die[v]==0){
			int j;
			for(j=dfn[v]+1;j<=dfn1[v];j++){
				int too=to[j];
				if(die[too]==1)continue;
				set<pair<int,int> >::iterator itt;
				 itt=st.find(make_pair(anss[too],too));
				if(itt==st.end())continue;
				st.erase(itt);
				anss[too]=min(anss[too],du[too]-du[v]);
				st.insert(make_pair(anss[too],too));
				//cout<<too<<' '<<anss[too]<<endl;
			}
			die[v]=1;
			v=fa[v];
		}
		st.erase(st.find(make_pair(anss[vv],vv)));
	}
	cout<<ans<<'\n';
}