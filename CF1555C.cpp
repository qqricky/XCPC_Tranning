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
int sum[2][N];
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
        int n;
        cin>>n;
        sum[1][0]=sum[0][0]=0;
        for(int j=0;j<=1;j++){
            for(int i=1;i<=n;i++){
                cin>>sum[j][i];
                sum[j][i]+=sum[j][i-1];
            }
        }
        int ans=INF;
        for(int i=1;i<=n;i++){
            ans=min(ans,max(sum[1][i-1],sum[0][n]-sum[0][i]));
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}