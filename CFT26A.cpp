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
int a[N],b[N];
ll ans=0;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n+1;i++){
        cin>>b[i];
    }
    for(int i=n+1;i>=1;i--){
        if(a[i]<b[i]){
            ans+=(b[i]-a[i]+1)/2;
            a[i-1]-=(b[i]-a[i]+1)/2;
        }
    }
    if(a[0]<0){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}