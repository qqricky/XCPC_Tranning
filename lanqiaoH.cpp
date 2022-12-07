#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
struct node
{
    ll x,y,r;
    int cnt;
    bool operator<(const node&b)const{
        return x+y<b.x+y;
    }
    bool operator==(const node&b)const{
        return (x==b.x)&&(y==b.y);
    }
}nd1[N],nd2[N],ndd1[N],ndd2[N];
bool vis[N]={};
vector<int>mp[N];
void dfs(int now){
    for(int x:mp[now]){
        if(!vis[x]){
            vis[x]=1;
            dfs(x);
        }
    }
}
double dis(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    ndd1[0].x=-1;
    ndd2[0].x=-1;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin>>nd2[i].x>>nd2[i].y>>nd2[i].r;
        nd2[i].cnt=0;
    }
    for(int i=1;i<=m;i++){
        cin>>nd1[i].x>>nd1[i].y>>nd1[i].r;
        nd1[i].cnt=0;
    }
    sort(nd1+1,nd1+m+1);
    sort(nd2+1,nd2+n+1);
    for(int i=1;i<=m;i++){
        if(!(nd1[i]==ndd1[cnt1])){
            ndd1[++cnt1]=nd1[i];
        }
        else{
            ndd1[cnt1].cnt++;
            ndd1[cnt1].r=max(ndd1[cnt1].r,nd1[i].r);
        }
    }
    for(int i=1;i<=n;i++){
        if(!(nd2[i]==ndd2[cnt2])){
            ndd2[++cnt2]=nd2[i];
        }
        else{
            ndd2[cnt2].cnt++;
            ndd2[cnt2].r=max(ndd2[cnt2].r,nd2[i].r);
        }
    }
    for(int i=1;i<=cnt1;i++){
        for(int j=1;j<=cnt2;j++){
            if(dis(ndd1[i].x,ndd1[i].y,ndd2[j].x,ndd2[j].y)<=ndd1[i].r){
                vis[j]=1;
            }
        }
    }
    for(int i=1;i<=cnt2;i++){
        for(int j=1;j<=cnt2;j++){
            if(i==j)continue;
            if(dis(ndd2[i].x,ndd2[i].y,ndd2[j].x,ndd2[j].y)<=ndd2[i].r){
                mp[i].push_back(j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt2;i++){
        if(vis[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=cnt2;i++){
        if(vis[i])ans++;
    }
    cout<<ans;
    //cout.flush();
    //system("pause");
    return 0;
}