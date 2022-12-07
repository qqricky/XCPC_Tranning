#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(3)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
vector<int>mp[21];
struct node
{
    int sta;
    ll prab;
    int pos;
};
ll p[21]={};
ll rev[22];
ll f[2*1024*1025][21];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        rev[i]=powq(i,mod-2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            read(x);
            //x=1;
            //if(i==j)x=0;
            if(x){
                mp[i].push_back(j);
            }
        }
    }
    queue<node>q;
    q.push((node){1,1,1});
    f[1][1]=1;int haha=0;
    while(q.size()){
        node x=q.front();
        haha++;
        q.pop();
        int now=x.pos;
        int sta=x.sta;
        ll prab=f[sta][now];
        ll cnt=0;
        for(int v:mp[now]){
            if(((sta>>(v-1))&1)==0){
                cnt++;
            }
        }
        if(cnt==0){
            p[now]=(p[now]+prab)%mod;
        }
        else{
            ll val=rev[cnt];
            for(int v:mp[now]){
                if(((sta>>(v-1))&1)==0){
                	if(f[sta^(1<<(v-1))][v]==0)
                    q.push((node){sta^(1<<(v-1)),prab*val%mod,v});
                    f[sta^(1<<(v-1))][v]+=prab*val%mod;
                    f[sta^(1<<(v-1))][v]%=mod;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",p[i]);
    }
    //cout<<haha<<endl;
    cout.flush();
    //system("pause");
    return 0;
}