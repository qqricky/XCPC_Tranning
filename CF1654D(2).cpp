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
ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}
vector<pair<int,int> >mp[N];
vector<int>mpp[N];
ll x=1;
ll ans=0;
const ll mod=998244353;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
void clac(){
    for(auto p:lcm){
        x=(ans*powq(p.first,p.second))%mod;
    }
    ans=x;
}
unordered_map<int,int>divd;
unordered_map<int,int>divu;
unordered_map<int,int>lcm;
void dfs(int now,int fa){
    for(int j=0;j<mpp[now].size();j++){
        if(mpp[now][j]==fa)continue;
        auto pr=mp[now][j];
        int u=mpp[now][j];
        ll b=pr.second;
        ll a=pr.first;
        for(ll i=2;i*i<=b;i++){
            while(b%i==0){
                b/=i;
                divu[i]++;
            }
        }
        if(b>1)divu[b]++;
        for(ll i=2;i*i<=a;i++){
            while(a%i==0){
                a/=i;
                divd[i]++;
            }
        }
        if(a>1)divd[a]++;
        for(auto &p:divd){
            int z=divu[p.first];
            if(divu[z]>0){
                int k=min(p.first,z);
                p.second-=k;
                divu[p.first]-=k;
            }
        }
        for(auto &p:divd){
            lcm[p.first]=max(lcm[p.first],p.second);
        }
        dfs(u,now);
        ll b=pr.second;
        ll a=pr.first;
        for(ll i=2;i*i<=b;i++){
            while(b%i==0){
                b/=i;
                if(divu[i]==0){
                    divd[i]++;
                }
                else{
                    divu[i]--;
                }
            }
        }
        if(b>1){
            if(divu[b]==0){
                divd[b]++;
            }
            else{
                divu[b]--;
            }
        }
        for(ll i=2;i*i<=a;i++){
            while(a%i==0){
                a/=i;
                if(divd[i]==0){
                    divu[i]++;
                }
                else{
                    divd[i]--;
                }
            }
        }
        if(a>1){
            if(divd[a]==0){
                divu[a]++;
            }
            else{
                divd[a]--;
            }
        }
    }
}
void dfss(int now,int fa){
    for(int j=0;j<mpp[now].size();j++){
        int u=mpp[now][j];
        auto p=mp[now][j];
        if(u==fa)continue;
        ans=(ans+x*p.second%mod*powq(p.first,mod-2)%mod)%mod;
        dfss(u,now);
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        x=1;
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)mp[i].clear(),mpp[i].clear();
        divd.clear(),divu.clear(),lcm.clear();
        for(int i=1;i<n;i++){
            int a,b,x,y;
            cin>>x>>y>>a>>b;
            ll d=gcd(a,b);
            a/=d;b/=d;
            mp[x].push_back(make_pair(a,b));
            mpp[x].push_back(y);
            mp[y].push_back(make_pair(b,a));
            mpp[y].push_back(x);
        }
        dfs(1,0);
        clac();
        dfss(1,0);
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}