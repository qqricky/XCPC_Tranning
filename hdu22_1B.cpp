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
bitset<2048>f[1070];
int v[1070],w[1070];
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
        for(int i=1;i<=n;i++){
            cin>>v[i]>>w[i];
        }
        for(int i=0;i<=1023;i++){
            f[i].reset();
        }
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=1023;j++){
                int val=j^w[i];
                f[j]|=(f[val]<<v[i]);
            }
        }
        // for(int i=1;i<=1024;i++){
        //     cout<<f[i]<<endl;
        // }
        int ans=-1;
        for(int i=0;i<=1023;i++){
            if(f[i][m]==1){
                ans=max(ans,i);
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}