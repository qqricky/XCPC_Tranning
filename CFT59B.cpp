#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int f[N];
int num[N];
ll dp[N];
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x<y){
        f[x]=y;
        num[y]+=num[x];
    }else if(x>y){
        f[y]=x;
        num[x]+=num[y];
    }
}
struct node
{
    int x,y,c;
    bool operator<(const node & b)const{
        return c<b.c;
    }
};
bool cmp(node a,node b){
    return a.c<b.c;
}
vector<node>v;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<=n;i++)f[i]=i,num[i]=1;
        v.clear();
        v.push_back((node){0,0,-1});
        for(int i=1;i<=m;i++){
            node nd;
            cin>>nd.x>>nd.y>>nd.c;
            v.push_back(nd);
        }
        sort(v.begin(),v.end());
        dp[0]=0;
        for(int i=1;i<=m;i++){
            dp[i]=dp[i-1];
            int x=v[i].x;
            int y=v[i].y;
            x=getfa(x);y=getfa(y);
            if(x!=y){
                dp[i]+=num[x]*num[y]*2;
                merge(x,y);
            }
        }
        int p;
        cin>>p;
        v.push_back((node){0,0,INF});
        dp[m+1]=n*(n-1);
        for(int i=1;i<=p;i++){
            int t;
            cin>>t;
            ll ans=n*(n-1);
            int pos=lower_bound(v.begin()+1,v.begin()+m+2,(node){0,0,t})-v.begin();
            pos--;
            // cout<<ans<<' '<<pos<<'\n';
            ans-=dp[pos];
            cout<<ans<<'\n';
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}