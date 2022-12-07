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
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,w,h;
        cin>>w>>h;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2>>x>>y;
        bool f1=(x2-x1+x>w);
        bool f2=(y2-y1+y>h);
        if(x>w||y>h||((x2-x1+x>w)&&(y2-y1+y>h))){
            cout<<-1<<endl;
            continue;
        }
        //cout<<f1<<' '<<f2<<'\n';
        int tmp=INF,tmpp=INF;
        if(!f2)
            tmp=max(0,y-max(h-y2,y1));
        if(!f1)
            tmpp=max(0,x-max(x1,w-x2));
        cout<<fixed<<setprecision(8)<<(double)min(tmp,tmpp)<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}