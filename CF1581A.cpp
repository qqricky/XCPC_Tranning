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
ll jie[N*2];
const ll mod=1e9+7;
void init()
{
    jie[2]=1;
    jie[1]=1;
    for(int i=3;i<=2e5;i++){
        jie[i]=jie[i-1]*i%mod;
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
    init();
    while(t--){
        int n;
        cin>>n;
        cout<<jie[2*n]<<'\n';
    }
    //cout.flush();
    //system("pause");
    return 0;
}