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
int getdis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
ll f[N][20];//17
int xx[N][2];
int yy[N][2];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    for(int i=1;i<n;i++){
        for(int j=0;j<=1;j++){
            cin>>yy[i][j]>>xx[i][j];
        }
    }

    cout.flush();
    system("pause");
    return 0;
}