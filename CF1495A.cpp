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
int a[N];
int b[N];
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
        int ncnt1=0,ncnt2=0;
        for(int i=1;i<=2*n;i++){
            int x,y;
            cin>>x>>y;
            if(x==0)a[++ncnt1]=abs(y);
            else b[++ncnt2]=abs(x);
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        long double ans=0;
        for(int i=1,j=n;i<=n;i++,j--){
            ans+=sqrt(1.0*a[i]*a[i]+1.0*b[i]*b[i]);
        }
        cout<<fixed<<setprecision(12)<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}