#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char color[N];
vector<int>mp[N];
int cnt[N][26];
int ind[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>color[i];
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        ind[y]++;
    }
    queue<int>q;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!ind[i]){
            cnt[i][color[i]-'a']=1;
            q.push(i);
        }
    }
    int cntt=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cntt++;
        if(mp[u].size()==0){
            for(int j=0;j<26;j++)ans=max(ans,cnt[u][j]);
            continue;
        }
        for(int i=0;i<mp[u].size();i++){
            ind[mp[u][i]]--;
            for(int j=0;j<26;j++){
                cnt[mp[u][i]][j]=max(cnt[mp[u][i]][j],cnt[u][j]);
            }
            if(ind[mp[u][i]]==0){
                cnt[mp[u][i]][color[mp[u][i]]-'a']++;
                q.push(mp[u][i]);
            }
        }
    }
    if(cntt!=n){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ans<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}