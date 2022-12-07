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
ll d[N];
const ll mod=998244353;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int x;
    d[1]=0;
    d[0]=0;
    d[2]=1;
    d[3]=2;
    for(int i=4;i<=1e5;i++){
        d[i]=(i-1)*(d[i-1]*d[n-2]%mod)%mod;
    }
    cout.flush();
    //system("pause");
    return 0;
}