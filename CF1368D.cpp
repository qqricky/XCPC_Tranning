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
ll a[N];
int num[33]={};
ll b[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int now=0;
        while(a[i]){
            if(a[i]&1){
                num[now]++;
            }
            a[i]>>=1;
            now++;
        }
    }
    for(int i=0;i<=30;i++){
        for(int j=1;j<=num[i];j++){
            b[j]+=(1<<i);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=b[i]*b[i];
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}