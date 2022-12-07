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
int ind[N];
int lev[N];
vector<int>mp[N];
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
        int n,m;
        cin>>n>>m;
        // memset(ind,0,sizeof(int)*(n+2));
        memset(lev,0,sizeof(int)*(n+2));
        vector<int>ans;
        for(int i=1;i<=n;i++){
            mp[i].clear();
        }
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            ind[y]++;
        }
        queue<int>q;
        // for(int i=1;i<=n;i++){
        //     if(ind[i]==0){
        //         q.push(i);
        //         lev[i]=1;
        //     }
        // }
        for(int i=1;i<=n;i++){
            if(lev[i]%3==2){
                ans.push_back(i);
                continue;
            }
            for(int v:mp[i]){
                lev[v]=max(lev[v],lev[i]+1);
            }
        }
        // while(!q.empty()){
        //     int v=q.front();
        //     q.pop();
        //     for(int u:mp[v]){
        //         if(!lev[u])lev[u]=lev[v]+1;
        //         ind[u]--;
        //         if(lev[u]==3){
        //             ans.push_back(u);
        //             for(int x:mp[u]){
        //                 ind[x]--;
        //                 if(ind[x]==0){
        //                     q.push(x);
        //                     lev[x]=1;
        //                 }
        //             }
        //         }
        //         if(ind[u]==0){
        //             q.push(u);
        //         }
        //     }
        // }
        cout<<ans.size()<<'\n';
        for(int x:ans){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}