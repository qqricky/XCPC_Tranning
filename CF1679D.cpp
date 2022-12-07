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
int n,m;
ll k;
int ind[N];
bool vis[N];
int val[N];
int f[N];
vector<int>mp[N];
vector<int>mpp[N];
bool ck(int x){
    memset(ind,0,sizeof(int)*(n+5));
    for(int i=1;i<=n;i++)vis[i]=1;
    memset(f,0,sizeof(int)*(n+5));
    int num=0;
    for(int i=1;i<=n;i++){
        if(val[i]<=x){vis[i]=0;num++;}
    }
    for(int i=1;i<=n;i++){
        mp[i].clear();
        if(!vis[i]){
            for(int v:mpp[i]){
                if(!vis[v]){
                    mp[i].push_back(v);
                    ind[v]++;
                }
            }
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&ind[i]==0){
            q.push(i);
            num--;
            f[i]=1;
            if(f[i]>=k)return 1;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:mp[u]){
            ind[v]--;
            f[v]=max(f[v],f[u]+1);
            if(f[v]>=k)return 1;
            if(ind[v]==0){
                q.push(v);
                num--;
            }
        }
    }
    if(num)return 1;
    else return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        mpp[x].push_back(y);
    }
    int l=1,r=1e9;
    int mid;
    if(!ck(1e9)){
        cout<<-1;
        return 0;
    }
    while(l<r){
        mid=(l+r)>>1;
        if(ck(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    mid=(l+r)>>1;
    cout<<mid;
    cout.flush();
    //system("pause");
    return 0;
}