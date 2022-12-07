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
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll k,l;
        cin>>k>>l;
        if(l>=2000){
            cout<<-1<<'\n';
            continue;
        }
        ll y;
        for(y=1000000;y>=1;y--){
            if(y*1999-k<=1000000){
                break;
            }
        }
        ll x=y*1999-k;
        y++;
        if(y>x){
            cout<<-1<<'\n';
            continue;
        }
        cout<<1999<<'\n';
        cout<<x<<' '<<-x<<' ';
        for(int i=1;i<=1995;i++){
            cout<<0<<' ';
        }
        cout<<"-1 ";
        cout<<y<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}