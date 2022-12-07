#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<pair<int,int> >v[N];
ll f[N]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,n;
    cin>>a>>n;
    for(int i=1;i<=a;i++){
        int h,d,t;
        cin>>h>>d>>t;
        for(int j=1;j<=t;j++){
            int tm;
            cin>>tm;
            int kk=tm;
            tm+=d;
            if(tm>n){
                tm=n+1;
            }
            v[tm].push_back(make_pair(kk,h));
        }
    }
    ll ans=0;
    for(int i=1;i<=n+1;i++){
        f[i]=f[i-1];
        for(auto x:v[i]){
            f[i]=max(f[i],f[x.first]+x.second);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}