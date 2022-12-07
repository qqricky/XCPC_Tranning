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
const int maxk=450;
ll a[N];
ll f[N][maxk+1]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        a[0]=0;
        int n;
        cin>>n;
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=maxk;j++){
                f[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        int ans;
        for(int i=n;i>=1;i--){
            f[i][1]=max(f[i+1][1],a[i]-a[i-1]);
            for(int j=2;j<=min(maxk,n-i);j++){
                f[i][j]=f[i+1][j];
                if(a[i+j-1]-a[i-1]>=f[i+j][j-1])continue;
                f[i][j]=max(f[i+1][j],a[i+j-1]-a[i-1]);
            }
        }
        for(int i=maxk;i>=1;i--){
            if(f[1][i]){
                ans=i;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}