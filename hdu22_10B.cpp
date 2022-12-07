#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
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
        ll ans=1e17;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)b[i]=a[i];
        ll res=0;
        a[0]=1e17;
        for(int i=1;i<=n;i++){
            if(i&1){
                if(a[i]>=a[i-1]){
                    res+=(a[i]-(a[i-1]-1));
                    a[i]=a[i-1]-1;
                }
            }else{
                if(a[i]<=a[i-1]){
                    res+=a[i-1]+1-a[i];
                    a[i]=a[i-1]+1;
                }
            }
        }
        ans=res;
        for(int i=1;i<=n;i++)a[i]=b[i];
        a[0]=-1e16;
        res=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                if(a[i]>=a[i-1]){
                    res+=(a[i]-(a[i-1]-1));
                    a[i]=a[i-1]-1;
                }
            }else{
                if(a[i]<=a[i-1]){
                    res+=a[i-1]+1-a[i];
                    a[i]=a[i-1]+1;
                }
            }
        }
        ans=min(ans,res);
        cout<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}