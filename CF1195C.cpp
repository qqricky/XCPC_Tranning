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
ll f[N][3]={};
int h[N][2];
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
        cin>>h[i][0];
    }
    for(int i=1;i<=n;i++){
        cin>>h[i][1];
    }
    for(int i=1;i<=n;i++){
        f[i][0]=max(f[i-1][1]+h[i][0],f[i-1][2]+h[i][0]);
        f[i][1]=max(f[i-1][0]+h[i][1],f[i-1][2]+h[i][1]);
        f[i][2]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]));
    }
    cout<<max(f[n][0],max(f[n][1],f[n][2]));
    cout.flush();
    //system("pause");
    return 0;
}