#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int zhen[2][1004][1004];
pair<int,int>pos[2][1000006];
bool vis[1000004];
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i;
	int n,m;
	cin>>n>>m;
	int ans=1;
	int j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)cin>>zhen[0][i][j],pos[0][zhen[0][i][j]]=make_pair(i,j);;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>zhen[1][i][j];
			pos[1][zhen[1][i][j]]=make_pair(i,j);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(vis[zhen[0][i][j]]==true)continue;
			int x=pos[1][zhen[0][i][j]].first;
			int y=pos[1][zhen[0][i][j]].second;
			int go1=1;
			int go2=1;
			int last=1000000;
			for(go1=1;go1<=min(n-i+1,n-x+1);go1++){
				for(go2=1;go2<=min(m-j+1,n-y+1);go2++){
					if(zhen[0][i+go1-1][j+go2-1]!=zhen[1][x+go1-1][y+go2-1]||go2==last){
						ans=max(ans,go1*(go2-1));
						last=go2;
						break;
					}else{
						vis[zhen[0][i+go1-1][j+go2-1]]=1;
					}
				}
				if(go2==min(m-j+1,n-y+1)+1){
					last=go2;
					ans=max(ans,go1*(go2-1));
				}
			}
		}
	}
	cout<<ans<<'\n';
}