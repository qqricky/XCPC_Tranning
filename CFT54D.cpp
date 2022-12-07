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
int a[N];
ll f[2070]={};
const ll mod=998244353;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0)continue;
        for(int j=n;j>=a[i];j--){
            f[j]=(f[j-a[i]]+f[j])%mod;
        }
    }
    int now=n;
    while(f[now]==0)now--;
    cout<<now<<' '<<f[now];
    cout.flush();
    // system("pause");
    return 0;
}