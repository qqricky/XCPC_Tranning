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
ll h[N];
ll f[N]={};
ll g[N]={};
const ll mod=1e9+7;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>h[i];
        if(h[1]!=0){
            cout<<0<<'\n';
            continue;
        }
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        g[0]=0;
        g[1]=1;
        bool flag=1;
        for(int i=2;i<=n;i++){
            if(h[i]<h[i-1]||h[i]+1<i||h[i]>n-1){
                flag=0;
                break;
            }
            if(h[i]==h[i-1]){
                g[i]=(g[i-1]*(h[i]+1-(i-1)))%mod;
            }
            else{
                g[i]=(g[i-1]*2)%mod;
            }
        }
        if(flag){
            cout<<g[n]%mod<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}