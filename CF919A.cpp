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
    int t=1;
    while(t--){
        int n,m;
        cin>>n>>m;
        int x,y;
        double pri=11451444;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            pri=min(pri,x*1.0/y);
        }
        cout<<fixed<<setprecision(7)<<m*pri<<endl;
    }
    cout.flush();
    //system("pause");
    return 0;
}