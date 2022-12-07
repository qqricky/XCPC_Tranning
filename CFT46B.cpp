#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mp[25][25]={};
int w,h;
int xa1[50],xa2[50],ya1[50],ya2[50];
double dp[1070];
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
void add(int xx1,int yy1,int xx2,int yy2){
    for(int i=xx1+1;i<=xx2;i++){
        for(int j=yy1+1;j<=yy2;j++){
            mp[i][j]++;
        }
    }
}
int num1=0;
int num2=0;
bool ck(int val){
    memset(mp,0,sizeof(mp));
    for(int j=0;j<n;j++){
        if(val&(1<<j)){
            add(to[xa1[j+1]],to2[ya1[j+1]],to[xa2[j+1]],to2[ya2[j+1]]);
        }
    }
    bool flag=1;
    for(int i=1;i<num1;i++){
        for(int j=1;j<num2;j++){
            if(mp[i][j]==0){
                flag=0;
                break;
            }
        }
    }
    //if(flag)cout<<val<<endl;
    return flag;
}
void dfs(int now){
    if(f[now]>0)return;
    int cnt=0;
    for(int j=0;j<n;j++){
        if(now&(1<<j)){
            cnt++;
        }
    }
    ll val=0;
    double tmp=0;
    int nn=0;
    for(int j=0;j<n;j++){
        if((now&(1<<j))==0){
            int ne=now|(1<<j);
            if(!vis[ne])dfs(ne);
            val=(val+f[ne])%mod;
            tmp+=dp[ne];
            if(dp[ne]==0)nn++;
        }
    }
    dp[now]=(dp[now]+(1.0*tmp+n)/(1.0*n-cnt));
    f[now]=(f[now]+powq(n-cnt,mod-2)*(val+n)%mod)%mod;
    //cout<<now<<"!!!"<<dp[now]<<"!!!"<<nn<<endl;
    //cout<<"so  "<<cnt<<endl;
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
        memset(dp,0,sizeof(dp));
        cin>>w>>h;
        num1=0,num2=0;
        vx.clear(),vy.clear();
        vx.push_back(0),vy.push_back(0);
        for(int i=1;i<=n;i++){
            cin>>xa1[i]>>ya1[i]>>xa2[i]>>ya2[i];
            if(xa1[i]>=w)xa1[i]=w;
            if(xa2[i]>=w)xa2[i]=w;
            if(ya2[i]>=h)ya2[i]=h;
            if(ya1[i]>=h)ya1[i]=h;
            vx.push_back(xa1[i]);
            vx.push_back(xa2[i]);
            vy.push_back(ya1[i]);
            vy.push_back(ya2[i]);
        }
        vx.push_back(w);vy.push_back(h);
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        num1=unique(vx.begin(),vx.end())-vx.begin();
        num2=unique(vy.begin(),vy.end())-vy.begin();
        to.clear();
        to2.clear();
        for(int j=0;j<num1;j++){
            to[vx[j]]=j;
        }
        for(int j=0;j<num2;j++){
            to2[vy[j]]=j;
        }
        bool can=0;
        for(int j=0;j<=(1<<n)-1;j++){
            if(ck(j)){
                //cout<<j<<endl;
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
        //cout<<fixed<<setprecision(6)<<dp[0]<<endl;
        cout<<f[0]%mod<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}