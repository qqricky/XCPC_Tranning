#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mp[25][25]={};
int w,h;
int x1[50],x2[50],y1[50],y2[50];
unordered_map<int,int>to;
unordered_map<int,int>to2;
vector<int>vx;
vector<int>vy;
ll f[1070];
bool vis[1070];
int du[1070];
const ll mod=998244353;
int n;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
int cnt1,cnt2;
void add(int x1,int x2,int y1,int y2){
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            mp[i][j]++;
        }
    }
}
bool ck(int val){
    memset(mp,0,sizeof(mp));
    for(int j=0;j<n;j++){
        if(val&(1<<j)){
            add(to[x1[j+1]],to2[y1[j+1]],to[x2[j+1]],to2[y2[j+1]]);
        }
    }
    bool flag=1;
    for(int i=0;i<=cnt1;i++){
        for(int j=0;j<=cnt2;j++){
            if(mp[i][j]==0){
                flag=0;
                break;
            }
        }
    }
    return flag;
}
void dfs(int now){
    int cnt=0;
    for(int j=0;j<n;j++){
        if(now&(1<<j)){
            cnt++;
        }
    }
    ll val=0;
    for(int j=0;j<n;j++){
        if((now&(1<<j))==0){
            int ne=now|(1<<j);
            if(f[ne]==0&&!vis[ne])dfs(ne);
            val=(val+f[ne]+1)%mod;
        }
    }
    f[now]=(f[now]+powq(n-cnt,mod-2)*(val+cnt)%mod)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        memset(du,0,sizeof(du));
        cin>>w>>h;
        cnt1=cnt2=0;
        vx.clear(),vy.clear();
        vx.push_back(0),vy.push_back(0);
        for(int i=1;i<=n;i++){
            cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
            if(x1[i]>=w)x1[i]=w;
            if(x2[i]>=w)x2[i]=w;
            if(y2[i]>=h)y2[i]=h;
            if(y1[i]>=h)y1[i]=h;
            vx.push_back(x1[i]);
            vx.push_back(x2[i]);
            vy.push_back(y1[i]);
            vy.push_back(y2[i]);
        }
        vx.push_back(w);vy.push_back(h);
        int cnt1=unique(vx.begin(),vx.end())-vx.begin();
        int cnt2=unique(vy.begin(),vy.end())-vy.begin();
        to.clear();
        for(int j=0;j<cnt1;j++){
            to[vx[j]]=j;
        }
        for(int j=0;j<cnt2;j++){
            to2[vy[j]]=j;
        }
        bool can=0;
        for(int j=0;j<=(1<<n)-1;j++){
            if(ck(j)){
                vis[j]=1;
                can=1;
            }
        }
        if(!can){
            cout<<-1<<'\n';
            continue;
        }
        // while(!q.empty()){
        //     int now=q.front();
        //     q.pop();
        //     for(int j=0;j<n;j++){
        //         int cnt=0;
        //         for(int i=0;i<n;i++){
        //             if((j>>i)&1)cnt++;
        //         }
        //         if(now&(1ll<<j)){
        //             int ne=now^(1ll<<j);
        //             if(vis[ne])continue;
        //             f[ne]=(f[ne]+powq(n-cnt,mod-2)*((f[now]+cnt+1)%mod)%mod)%mod;
        //             q.push(ne);
        //         }
        //     }
        // }
        dfs(0);
        cout<<f[0]%mod<<'\n';
    }
    return 0;
}