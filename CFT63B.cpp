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
ll b[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        a[0]=0;a[n+1]=0;
        for(int i=1;i<=n+1;i++){
            b[i]=a[i]-a[i-1];
        }
        bool flag=1;
        int p1=1;
        int p2=1;
        while(p1<=n+1&&p2<=n+1){
            while(p1<=n+1&&b[p1]<=0)p1++;
            while(p2<=n+1&&b[p2]>=0)p2++;
            if(p1>n+1||p2>n+1)break;
            if(p2-p1<3){
                flag=0;
                break;
            }
            if(b[p1]>=-b[p2]){
                b[p1]+=b[p2];
                b[p2]=0;
            }else{
                b[p2]+=b[p1];
                b[p1]=0;
            }
        }
        cout<<"Case #"<<cas<<": ";
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    // cout.flush();
    // system("pause");
    return 0;
}