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

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int n=1;n<=100;n++){
        int x=1;
        bool fl=0;
        while(x<=n){
            if(x==n || x+1==n) {
                cout<<n<<' '<<1<<'\n';
                fl=1;
                break;
            }
            if(x&1) x=x+1+x+1;
            else x=x+1+x;
        }
        if(fl)continue;
        // cout<<n<<' '<<0<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}