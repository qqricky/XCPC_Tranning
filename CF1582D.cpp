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
ll a[N];
ll b[N];
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
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n&1){
            int st=4;
            if(a[1]+a[2]==0){
                b[1]=-a[3];
                b[2]=a[3];
                b[3]=a[1]-a[2];
            }
            else{
                b[1]=b[2]=a[3];
                b[3]=-(a[1]+a[2]);
            }
            for(int i=4,j=n;i<=n;i++,j--){
                if(i<=j){
                    b[i]=-a[j];
                }
                else{
                    b[i]=a[j];
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(i<=n/2){
                    b[i]=-a[n-i+1];
                }
                else{
                    b[i]=a[n-i+1];
                }
            }
        }
        for(int i=1;i<=n;i++)cout<<b[i]<<' ';
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}