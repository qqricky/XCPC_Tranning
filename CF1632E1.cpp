#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=6e3+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
int maxd=0,num=0;
int dep[N]={};
int ma[N]={};
int f[N]={};
int pos;
void dfs(int now,int fa,int depp){
    dep[now]=depp;
    if(mp[now].size()==1&&mp[now][0]==fa){
        ma[now]=dep[now];
        if(depp>maxd){
            maxd=depp;
            pos=now;
        }
    }
    for(int v:mp[now]){
        if(v==fa)continue;
        f[v]=now;
        dfs(v,now,depp+1);
        ma[now]=max(ma[now],ma[v]);
    }
}
vector<int>r;
int calc(int x){
    int ans=ma[1];
    for(int v:r){
        if(dep[v]<=x)continue;
        int tmp=max(ma[v]-(dep[v]-x),dep[v]-1);
        int u=f[v];
        for(int son:mp[u]){
            if(son==f[u])continue;
            if(son==v)continue;
            tmp=max(tmp,ma[son]);
        }
        ans=min(ans,tmp);
    }
    return ans;
}
int anss=INF;
void calc2(int x,int v){
    if(dep[v]<=x)return;
        int tmp=max(ma[v]-(dep[v]-x),dep[v]-1);
        tmp=max(tmp,x);
        int u=f[v];
        int pre=v;
        int poss=u;
        while(poss!=0){
            for(int son:mp[poss]){
                if(son==f[poss])continue;
                if(son==pre)continue;
                tmp=max(tmp,ma[son]);
            }
            pre=poss;
            poss=f[poss];
        }
        anss=min(anss,tmp);
}
void dfs2(int now,int fa,int x){
        calc2(x,now);
    for(int v:mp[now]){
        if(v==fa)continue;
        dfs2(v,now,x);
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            mp[i].clear();
        }
        r.clear();
        pos=1;
        anss=INF;
        memset(dep,0,sizeof(int)*(n+2));
        memset(ma,0,sizeof(int)*(n+2));
        memset(f,0,sizeof(int)*(n+2));
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        maxd=0,num=0;
        dfs(1,0,0);
        // while(pos!=1){
        //     r.push_back(pos);
        //     pos=f[pos];
        // }
        // reverse(r.begin(),r.end());
        for(int i=1;i<=n;i++){
            anss=ma[1];
            dfs2(1,0,i);
            cout<<anss<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}