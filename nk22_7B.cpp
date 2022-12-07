#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
bool vis[N]={};
int a[N];
int nxt[N];
int pre[N];
deque<int>q;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nxt[i]=i+1;
        pre[i]=i-1;
    }
    a[n+1]=-1e9;
    for(int i=1;i<=n;){
        int nx=nxt[i];
        if(a[i]==a[nxt[i]]){
            vis[i]=vis[nx]=1;
            ans++;
            pre[nxt[nx]]=pre[i];
            nxt[pre[i]]=nxt[nx];
            i=pre[i];
        }else if(a[i]+a[nxt[i]]==k){
            vis[i]=vis[nx]=1;
            ans++;
            pre[nxt[nx]]=pre[i];
            nxt[pre[i]]=nxt[nx];
            i=pre[i];
        }else{
            i=nxt[i];
        }
        if(i==0)i=nxt[i];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.push_back(a[i]);
        }
    }
    while(q.size()>1){
        int x=q.front();
        int y=q.back();
        q.pop_back();
        q.pop_front();
        if(x==y){
            ans++;
        }else if(x+y==k){
            ans++;
        }else{
            break;
        }
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}