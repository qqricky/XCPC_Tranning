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
const double delta=0.992;
const double eps=1e-14;
ll ans;
void SA(){
    for(double T=5000;T>=eps;T*=delta){

    }
}
ll a[200][200];
int p[200];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        ans*=
    }
    for(int i=1;i<=n;i++)p[i]=i;
    while((double)clock()/CLOCKS_PER_SEC<0.85)SA();
    cout.flush();
    system("pause");
    return 0;
}