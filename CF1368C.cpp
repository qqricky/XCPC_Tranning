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
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    cout<<3*k+4<<'\n';
    cout<<"0 0\n0 1\n";
    for(int i=1;i<=k;i++){
        for(int j=i-1;j<=i+1;j++){
            cout<<i<<' '<<j<<'\n';
        }
    }
    cout<<k+1<<' '<<k<<'\n';
    cout<<k+1<<' '<<k+1<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}