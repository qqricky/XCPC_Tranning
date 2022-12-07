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
    int l,r,p;
    cin>>l>>r>>p;
    if(l>=r){
        if(1.0*l*p/100<=r){
            cout<<"Ambidextrous";
        }
        else{
            cout<<"Left-handed";
        }
    }
    else{
        if(1.0*r*p/100<=l){
            cout<<"Ambidextrous";
        }
        else{
            cout<<"Right-handed";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}