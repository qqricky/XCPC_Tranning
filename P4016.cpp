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
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    int ans=0;
    for(int i=1;i<=n;i++){
        a[i]-=sum;
        a[i]+=a[i-1];
    }
    nth_element(a+1,a+(n+1)/2,a+n+1);
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-a[(n+1)/2]);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}