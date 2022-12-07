#include<bits/stdc++.h>
#define next NEXT
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int head[N],next[N],ver[N],tot,fa[N],a[N];
int Head[N],Next[N],Ver[N],Tot,A[N];
vector<int>mp[N];
int ind[N];
int cnt ;
int val[N];
bool vis[N]={};
void add(int x,int y){
	ver[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
}
void Add(int x,int y){
	Ver[++Tot] = y;
	Next[Tot] = Head[x];
	Head[x] = Tot;
	mp[x].push_back(y);
	ind[x]++;
}
int get(int x){
	return (x==fa[x])?x:(fa[x]=get(fa[x]));
}
void dfs(int x,int pre){
	if(pre){
		if(a[pre]==a[x]) fa[x] = get(x);
	}
	for(int i = head[x];i;i=next[i]){
		int y = ver[i];
		if(y==pre) continue;
		dfs(y,x);
	}
}
int main(){
	int n;cin >> n;
    getchar();
	for(int i = 1;i <= n;++i){
		char c = getchar();
		if(c=='N') a[i] = 0;
		else a[i] = 1;
		getchar();
	}
	for(int i = 1;i < n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i = 1;i <= n;++i) fa[i] = i;
	dfs(1,0);
	for(int i = 1;i <= n;++i) fa[i] = get(i);
	cnt = 0;
	for(int i = 1;i <= n;++i) 
		if(fa[i]==i){
			++cnt;
			A[cnt] = a[i];
			for(int j = head[i];j;j=next[j]){
				int y = ver[j];
				if(y==fa[y]){
					Add(i,y);
				}
			}
		}
    queue<int>q;
    for(int i=1;i<=cnt;i++){
        if(ind[i]==1){
            q.push(i);
        }
        val[i]=1;
        vis[i]=1;
    }
    for(int i=1;i<=3;i++)cout<<ind[i]<<endl;
    int ma=0;
    while(!q.empty()){
        int u=q.front();
        vis[u]=1;
        ma=max(ma,val[u]);
        q.pop();
        for(int j=0;j<mp[u].size();j++){
            if(vis[mp[u][j]])continue;
            val[mp[u][j]]=val[u]+1;
            ind[mp[u][j]]--;
            if(ind[mp[u][j]]==1){
                q.push(mp[u][j]);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=cnt;i++){
        if(val[i]==ma){
            if(A[i]==0){
                ans=min(ans,ma);
            }
            else{
                ans=min(ans,ma-1);
            }
        }
    }
    cout<<ans;
    cout.flush();
    system("pause");
	return 0;
}