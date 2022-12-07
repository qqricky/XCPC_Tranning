#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll sum[N]={};
ll a[N];
int c[2*N]={};
bool vis[2*N]={};
struct node
{
    ll x,ans;
    int rk;
    bool operator<(const node&b)const{
        return 1;
    }
};
set<node>s;
ll mxx=0;
void add(int pos,int x){
    for(int i=pos;i<=mxx;i+=(i&-i)){
        c[i]+=x;
    }
}
ll ask(int pos){
    ll ans=0;
    for(int i=pos;i;i-=(i&-i)){
        ans+=c[i];
    }
    return ans;
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
        int n;
        cin>>n;
        mxx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mxx=max(mxx,a[i]);
        }
        mxx*=2;
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        memset(sum,0,sizeof(sum));
        for(int i=2;i<=n;i++){
            if(a[i]>a[1]){
                swap(a[1],a[i]);
                sum[i]++;
            }
        }
        vis[a[1]]=1;
        add(a[1],1);
        for(int i=2;i<=n;i++){
            int rk=ask(mxx)-ask(a[i]);
            sum[i]+=rk;
            if(!vis[a[i]]){
                add(a[i],1);
                vis[a[i]]=1;
            }
        }
        for(int i=1;i<=n;i++){
            sum[i]+=sum[i-1];
            cout<<sum[i];
            if(i!=n){
                cout<<' ';
            }
            else cout<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}