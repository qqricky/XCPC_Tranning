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
ll mod;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
bool  vis[N]={};
int num[N]={};
set<int>cannot;
set<int>can;
vector<int>v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool flag=0;
    cin>>mod;
    ll p=mod;
    int now=0;
    set<ll>s;
    if(mod==2){
        int x;
        cin>>x;
        x%=2;
        if(x==1)cout<<"Yes";
        else cout<<"No";
        return 0;
    }
    for(int i=1;i<mod;i++){
        ll x;
        cin>>x;
        x%=mod;
        if(x==0)continue;
        //v.push_back(x);
        num[x]++;
        if(x==1)flag=1;
    }
    if(flag){
        cout<<"Yes";
        return 0;
    }
    for(int i=1;i<p;i++){
        ll x=i;
        if(num[i]==0)continue;
        vector<ll>tmp;
        if(s.size()>p/2+100){
            flag=1;
            break;
        }
        if(s.count(1)){
            flag=1;
            break;
        }
        set<ll>st[2];
        for(ll y:s){
            ll val=1ll*y*x%mod;
            if(!vis[val])tmp.push_back(val);
            vis[val]=1;
        }
        if(num[i]>1){
            for(ll val:tmp){
                st[1].insert(val);
            }
        }
        if(!vis[x]){
            st[1].insert(x);
            vis[x]=1;
            tmp.push_back(x);
        }
        now=1;
        for(int j=2;j<=num[i];j++){
            now=now^1;
            st[now].clear();
            int pre=now^1;
            int add=0;
            for(ll y:st[pre]){
                ll val=1ll*y*x%mod;
                if(!vis[val]){
                    tmp.push_back(val);
                    st[now].insert(val);
                    add++;
                }
                vis[val]=1;
            }
            if(add==0)break;
            // st[pre]=st[now];
            // st[now].clear();
        }
        for(ll y:tmp){
            s.insert(y);
        }
    }
    if(s.count(1)){
        flag=1;
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    cout.flush();
    //system("pause");
    return 0;
}