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
int f[10070][2020];
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
        memset(f,0x3f,sizeof(int)*((n+2)*2020));
        f[1][0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int k=0;k<=2000;k++){
                if(a[i]>=k){
                    f[i+1][0]=min(f[i+1][0],f[i][k]+a[i]-k);
                    f[i+1][k+a[i]]=min(f[i+1][k+a[i]],max(f[i][k],k+a[i]));
                }
                else{
                    f[i+1][k+a[i]]=min(f[i+1][k+a[i]],max(f[i][k],k+a[i]));
                    f[i+1][k-a[i]]=min(f[i+1][k-a[i]],f[i][k]);
                }
            }
        }
        int ans=INF;
        // cout<<"what\n";
        // for(int i=0;i<=6;i++)cout<<f[n][i]<<' ';
        // cout<<endl;
        for(int i=0;i<=2000;i++){
            ans=min(ans,f[n+1][i]);
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}