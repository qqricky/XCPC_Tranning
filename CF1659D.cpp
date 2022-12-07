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
int b[N];
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
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=-1;
        }
        int st=1;
        while(a[st]==0){
            b[st]=0;
            st++;
        }
        for(int i=st;i<=n;i++){
            if(b[i]==-1)b[i]=1;
            int val=(i-1)*b[i];
            b[i+a[i]-val]=0;
        }
        for(int i=1;i<=n;i++)cout<<b[i]<<' ';
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}