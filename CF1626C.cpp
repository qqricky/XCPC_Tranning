#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e4+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll k[N],h[N];
bool dismiss[N];
ll to[N]={};
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
        memset(dismiss,0,sizeof(int)*(n+2));
        for(int i=1;i<=n;i++)cin>>k[i];
        for(int i=1;i<=n;i++)cin>>h[i];
        for(int i=1;i<=n;i++)to[i]=h[i];
        for(int i=1;i<=n;i++){
            int st=k[i]-h[i]+1;
            int pos=i-1;
            while(k[pos]>=st){
                if(h[pos]<=h[i]-(k[i]-k[pos])){
                    dismiss[pos]=1;
                }
                else{
                    to[i]=to[pos]+k[i]-k[pos];
                    dismiss[pos]=1;
                    break;
                }
                pos--;
            }
        }
        ll ans=0;
        int acu=0;
        for(int i=1;i<=n;i++){
            if(dismiss[i]){
                acu+=k[i]-k[i-1];
                continue;
            }
            ans+=to[i]*(to[i]+1)/2;
            // if(to[i]==i){
            //     ans+=h[i]*(h[i]+1)/2;
            //     acu=0;
            // }
            // else{
            //     ans+=(acu+k[i]-k[i-1])*h[to[i]];
            //     acu=0;
            // }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}