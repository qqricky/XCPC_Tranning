#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+100;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll f[2][N]={};
int a[N];
const ll mod=998244353;
vector<ll>v[2];
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
        ll ans=0;
        int ma=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ma=max(ma,a[i]);
        }
        memset(f,0,sizeof(ll)*(ma+3)*2);
        v[n&1].clear();
        for(int i=n;i>=1;i--){
            int x=i&1;
            v[x].push_back(a[i]);
            f[x][a[i]]=1;
            for(int j=0;j<v[x].size();j++){
                int val=a[i-1]/((a[i-1]+v[x][j]-1)/v[x][j]);
                int num=a[i-1]/a[i];
                f[x^1][num]+=f[x][v[x][j]];
                ans=(ans+i*f[x][num]%mod*(a[i]/v[x][j]-1)%mod)%mod;
                v[x^1].push_back(num);
            }
            v[x].clear();
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}