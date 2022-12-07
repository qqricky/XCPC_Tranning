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
ll a[N],b[N];
ll c[N];
bool vis[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum1=0;
    ll sum2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1^=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        c[i]=b[i]^a[i];
        sum2^=b[i];
    }
    for(int j=60;j>=0;j--){
        int x=((sum1>>j)&1);
        int y=((sum2>>j)&1);
        if(x^y)continue;
        if(x+y==0){
            
            break;
        }
        else{
            break;
        }
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(vis[i])cout<<i<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}