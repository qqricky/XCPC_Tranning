#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+10;
#define INF 0x3f3f3f3f
int a[N];
vector<int>mp[N];
int col[N];
int h[N]={};
bool ck(int i,int j,int k){
    int d2=abs(h[j]-h[k]);
    int d3=abs(h[i]-h[k]);
    if(d2==d3)return 1;
    return 0;
}
void dfs(int now,int fa){
    for(int x:mp[now]){
        if(x==fa)continue;
        h[x]=h[now]+1;
        dfs(x,now);
    }
}
int ans=0;
vector<int>v1;
vector<int>v2;
void cnt1(int now,int fa){
    v1.push_back(now);
    for(int x:mp[now]){
        if(x==fa)continue;
        cnt1(x,now);
    }
}
// void cnt2(int now,int fa){
//     v2.push_back(now);
//     for(int x:mp[now]){
//         if(x==fa)continue;
//         cnt2(x,now);
//     }
// }
void cnt(int now,int fa){
    v1.clear();
    v2.clear();
    for(int x:mp[now]){
        if(x==fa)continue;
        // cnt2(x,now);
        for(int i:v1){
            for(int j:v2){
                int k=now;
                if(col[i]==col[j]||col[i]==col[k]||col[j]==col[k])continue;
                    if(ck(i,j,k))ans++;
            }
        }
        cnt1(x,now);
    }
}
void solve(int now,int fa){
    cnt(now,fa);
    for(int x:mp[now]){
        if(x==fa)continue;
        solve(x,now);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i=1;i<=n;i++)cin>>col[i];
    dfs(1,0);
    solve(1,0);
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         for(int k=j+1;k<=n;k++){
    //             if(col[i]==col[j]||col[i]==col[k]||col[j]==col[k])continue;
    //             if(ck(i,j,k))ans++;
    //         }
    //     }
    // }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}