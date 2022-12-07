#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N]; 
int to[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        memset(to,0,sizeof(int)*(2*n));
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*a[i]<=2*i-1;j++){
                if(to[j]&&a[i]*j==i+to[j]){
                    ans++;
                }
            }
            to[a[i]]=i;
        }
        cout<<ans<<"\n";
    } 
    cout.flush();
    //system("pause");
    return 0;
}