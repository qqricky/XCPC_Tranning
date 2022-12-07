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
bool ck(int x,int y){
    if(x==y)return 1;
    if(x>=1e7||x<1)return 1;
    if(y>=1e7||y<1)return 1;
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cout<<1e5<<endl;
    srand(time(NULL));srand(rand());srand(rand());
    for(int i=1;i<=1e5-2;i++){
        srand(rand());
        int x=rand()%(10000001);
        int y=rand()%(10000001);
        int k;
        k=rand()%(max(x,y));
        while(ck(x,y)){
            x=rand()%(10000001);
            y=rand()%(10000001);
            k=rand()%(max(x,y));
        }
        cout<<x<<' '<<y<<' '<<k<<endl;
    }
    cout<<1<<' '<<2<<' '<<17<<'\n';
    cout<<2<<' '<<1<<' '<<17<<'\n';
    //cout.flush();
    //system("pause");
    return 0;
}