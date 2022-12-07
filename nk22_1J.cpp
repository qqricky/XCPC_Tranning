#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(3)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n;
// int f[N];
unordered_map<int,int>cnt;
unordered_map<int,int>v;
int col[N];
int du[N];
vector<int>mp[N];
int p[N];
int num=0;
bool vis[N]={};
// bool go(int now){
//     if(col[now]&&val!=0&&col[now]!=val){
//         return 0;
//     }
//     for(int x:mp[now]){
//         if(du[x]==cnt[x]){
//             go(x);
//         }
//     }
// }
void dfs(int now){
    if(v[now])return;
    num++;
    v[now]=1;
    vis[now]=1;
    for(int x:mp[now]){
        cnt[x]++;
        if(cnt[x]==du[x]){
            dfs(x);
        }
    }
}
void color(int now){

}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    srand(time(0));
    // srand(rand());
    int t;
    read(t);
    int ca=0;
    while(t--){
        read(n);
        ca++;
        memset(du,0,sizeof(int)*(n+5));
        // memset(col,0,sizeof(int)*(n+5));
        memset(vis,0,sizeof(bool)*(n+5));
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<=n;i++){
            int k;
            read(k);
            for(int j=1;j<=k;j++){
                int x;
                read(x);
                mp[x].push_back(i);
                du[i]++;
            }
        }
        for(int i=1;i<=n;i++)p[i]=i;
        random_shuffle(p+1,p+n+1);
        random_shuffle(p+1,p+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            int now=p[i];
            if(vis[now])continue;
            cnt.clear();
            v.clear();
            num=0;
            dfs(now);
            ans=max(ans,num);
        }
        // for(int i=1;i<=n;i++){
        //     int now=p[i];
        //     cnt.clear();
        //     val=0;
        //     num=0;
        //     bool can=go(now);
        //     if(can)color(now);
        // }
        printf("Case #%d: %d\n",ca,ans);
        // cout<<"Case "<<"#"<<ca<<": "<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}