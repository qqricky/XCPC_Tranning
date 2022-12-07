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
        int x,n,m;
        cin>>x>>n>>m;
        while(x>=21&&n>0){
            x=x/2+10;
            n--;
        }
        bool fl=0;
        while(m>0){
            x-=10;
            m--;
            if(x<=0){
                fl=1;
                break;
            }
        }
        if(fl)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}