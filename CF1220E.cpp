#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll w[N];
vector<int>mp[N];
ll du[N]={};
ll cnt[N]={};
queue<int>q;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
        du[x]++,du[y]++;
    }
    int s;
    cin>>s;
    for(int i=1;i<=n;i++){
        if(du[i]==1&&i!=s){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        du[now]=0;
        for(int u:mp[now]){
            du[u]--;
            cnt[u]=max(cnt[u],cnt[now]+w[now]);
            if(du[u]==1&&u!=s){
                q.push(u);
            }
        }
    }
    ll ans=0;
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(du[i]>=1||i==s){
            sum+=w[i];
        }
        ans=max(ans,cnt[i]);
    }
    cout<<ans+sum;
    cout.flush();
    //system("pause");
    return 0;
}