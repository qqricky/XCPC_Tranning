#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
ll a[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    while(cin>>n>>m){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]*=i;
        }
        a[n+1]=1e10;
        sort(a+1,a+n+1);
        int ans=1;
        ll sum=a[1];
        while(ans*sum<=m&&ans<=n){
            ans++;
            sum+=a[ans];
        }
        cout<<ans-1<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}