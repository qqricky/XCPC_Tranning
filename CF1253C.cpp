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
int n,m;
ll a[N];
ll add[N];
ll f[N];
ll sum[N];
void init(){
    add[0]=f[0]=0;
    for(int i=0;i<n;i++){
        sum[i%m]+=a[i];
        add[i+1]=sum[i%m];
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    init();
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+add[i];
        cout<<f[i]<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}
