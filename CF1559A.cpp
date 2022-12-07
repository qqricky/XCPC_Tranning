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
int num[1005];
int a[N];
void divide(int x)
{
    int cnt=0;
    while(x)
    {
        num[cnt]+=x%2;
        x/=2;
        cnt++;
    }
}
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
        ll ans=0;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            divide(a[i]);
        }
        for(int i=0;i<=50;i++){
            if(num[i]==n)ans+=(1<<i);
        }
        cout<<ans<<endl;
    }
    //cout.flush();
    //system("pause");
    return 0;
}