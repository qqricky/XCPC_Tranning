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
    while(t--){
        int x1,x2,p1,p2;
        cin>>x1>>p1>>x2>>p2;
        int val1=log10(x1);
        int val2=log10(x2);
        if(x1<x2){
            while(val1<val2){
                x1*=10;
                val1++;
                p1--;
            }
        }
        else if(x1>x2){
            while(val2<val1){
                x2*=10;
                val2++;
                p2--;
            }
        }
        if(p1==p2){
            if(x1>x2)cout<<'>';
            else if(x1<x2)cout<<"<";
            else cout<<'=';
        }
        else if(p1>p2)cout<<'>';
        else cout<<'<';
        cout<<"\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}