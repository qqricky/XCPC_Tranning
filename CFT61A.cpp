#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
vector<pair<int,ll> >mp[N];
ll sum=0;
ll ans=0;
ll n,m;
ll ncnt=0;
ll len;
vector<ll>v[N];
void dfs(int now,ll mi,int cnt){
    if(now==n){
        len=cnt;
        sum-=cnt*mi;
        return;
    }
    for(auto pr:mp[now]){
        v[ncnt].push_back(pr.second);
        dfs(pr.first,min(mi,pr.second),cnt+1);
    }
}
map<ll,ll>num;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        mp[x].push_back(make_pair(y,z));
        sum+=z;
    }
    for(auto pr:mp[1]){
        v[++ncnt].push_back(pr.second);
        dfs(pr.first,pr.second,1);
    }
    for(int i=1;i<=ncnt;i++){
        sort(v[i].begin(),v[i].end());
        v[i].push_back(1e15);
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]!=v[i][j+1]){
                num[j+1]+=v[i][j+1]-v[i][j];
            }
        }
    }
    for(auto pr:num){
        if(sum<1ll*len*pr.second){
            ll tmp=sum/len;
            ans+=1ll*tmp*pr.first;
            break;
        }
        sum-=1ll*len*pr.second;
        ans+=1ll*pr.first*pr.second;
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}