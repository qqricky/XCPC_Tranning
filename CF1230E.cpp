#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll val[N];
vector<int>mp[N];
const ll mod=1e9+7;
ll ans=0;
ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}
void dfs(int now,int fa,unordered_map<ll,int>cnt){
    unordered_map<ll,int>cntt;
    for(auto x : cnt){
        ll GCD=gcd(x.first,val[now]);
        cntt[GCD]+=x.second;
        ans=(ans+x.second*GCD)%mod;
    }
    ans=(ans+val[now])%mod;
    cntt[val[now]]++;
    for(int j=0;j<mp[now].size();j++){
        if(mp[now][j]==fa)continue;
        dfs(mp[now][j],now,cntt);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    unordered_map<ll,int>cnt;
    dfs(1,0,cnt);
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}