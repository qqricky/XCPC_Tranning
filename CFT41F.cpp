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
unordered_map<ll,int>f;
struct node
{
    ll x,y;
    bool is;
}nd[N];
bool cmp(node &a,node &b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}
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
        ll n,h,m;
        cin>>h;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>nd[i].x>>nd[i].y;
        }
        cin>>m;
        for(int i=n+1;i<=n+m;i++){
            cin>>nd[i].x>>nd[i].y;
            nd[i].is=1;
        }
        sort(nd+1,nd+n+m+1,cmp);
        f.clear();
        int ans=0;
        for(int i=1;i<=n+m;i++){
            ll k1=(nd[i].x-nd[i].y+2*h)%(2*h);
            ll k2=(nd[i].x+nd[i].y)%(2*h);
            ll h1=nd[i].y;
            ll h2=h-nd[i].y;
            if(nd[i].is){
                f[(k1-2*h1+2*h)%(2*h)]=max(f[(k1-2*h1+2*h)%(2*h)],f[k1]);
                f[(k2-2*h2+2*h)%(2*h)]=max(f[(k2-2*h2+2*h)%(2*h)],f[k2]);
            }
            else{
                f[k1]++;
                f[k2]++;
                ans=max(ans,max(f[k1],f[k2]));
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}