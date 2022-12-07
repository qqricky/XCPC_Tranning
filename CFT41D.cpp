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
int c[2*N]={};
bool vis[2*N]={};
int mxx=0;
int mx=0;
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
int a[N];
ll f[N];
int cnt=0;
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
        mx=0;
        mxx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mxx=max(mxx,a[i]);
        }
        mxx*=2;
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        // memset(c,0,sizeof(int)*(2*n+2));
        // memset(vis,0,sizeof(bool)*(2*n+2));
        f[1]=0;
        vis[a[1]]=1;
        add(a[1],1);
        mx=a[1];
        cnt=1;
        for(int i=2;i<=n;i++){
            if(a[i]>mx){
                f[i]=f[i-1]+2+cnt-1;
                mx=a[i];
                add(a[i],1);
                vis[a[i]]=1;
                cnt=1;
                continue;
            }
            if(a[i]==mx)cnt++;
            ll rk=1ll*ask(mxx)-ask(a[i])+1;
            f[i]=f[i-1]+rk-1;
            if(!vis[a[i]]){
                vis[a[i]]=1;
                add(a[i],1);
            }
        }
        for(int i=1;i<n;i++)cout<<f[i]<<' ';
        cout<<f[n];
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}