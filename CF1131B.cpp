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
int a[N],b[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    int ans=0;
    while(t--){
        int n;
        cin>>n;
        a[0]=b[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            if(a[i]==a[i-1]&&b[i]==b[i-1])continue;
            if(a[i]==b[i])ans--;
            int x=max(a[i-1],b[i-1]);
            int y=min(a[i],b[i]);
            if(y>=x){
                ans+=y-x+1;
            }
        }
        if(a[n]==b[n])ans++;
        cout<<ans;
    }
    cout.flush();
    //system("pause");
    return 0;
}