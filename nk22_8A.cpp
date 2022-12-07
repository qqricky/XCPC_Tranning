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
unordered_map<ll,int>pos;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        pos.clear();
        ll n,m;
        ll a,b,c,p,x;
        cin>>n>>m>>p>>x;
        // cin>>p>>x;
        ll ori=x;
        cin>>a>>b>>c;
        for(int i=1;i<=n;i++){
            x=(a*x*x+b*x+c)%p;
            if(pos[x])continue;
            else pos[x]=i;
        }
        ll ans=0;
        ll res=0;
        for(int i=1;i<=m;i++){
            x=(a*x*x%p+b*x+c)%p;
            if(pos[x]){
                ans=m-i+1;
                ans=min(ans,n-pos[x]+1);
                res=max(res,ans);
            }
        }
        cout<<res<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}