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
bool ask(ll x,ll y){
    cout<<'?'<<' '<<x<<' '<<y<<endl;
    fflush(stdout) ;
    char ch;
    cin>>ch;
    if(ch=='e'){
        return 0;
    }
    if(ch=='y')return 1;
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    while(str[0]=='s'){
        ll l=0,r=1;
        bool is=ask(l,r);
        while(is){
            l=r,r*=2;
            is=ask(l,r);
        }
        ll pos=l;
        l++;
        if(ask(r,r-1)){
            // r--;
            l=r;
        }
        while(l<r){
            ll mid=(l+r)>>1;
            if(ask(mid,pos)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<'!'<<' '<<r<<endl;
        fflush(stdout) ;
        cin>>str;
        if(str[0]=='m'){
            return 0;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}