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
inline ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin>>a>>b;
    if(a<b)swap(a,b);
    int GCD=gcd(a,b);
    if(GCD==a||GCD==b){
        cout<<0;
        return 0;
    }
    ll tmp,ans,anss,k;
    ans=a*b/gcd(a,b);
    anss=0;
    for(ll i=2;i*i<=a-b;i++){
        if((a-b)%i!=0)continue;
        tmp=a/i;
        if(tmp*i<a)tmp++;
        k=tmp*i-a;
        if((a+k)*(b+k)/i<ans){
            ans=(a+k)*(b+k)/i;
            anss=k;
        }
        ll ii=(a-b)/i;
        tmp=a/ii;
        if(tmp*ii<a)tmp++;
        k=tmp*ii-a;
        if((a+k)*(b+k)/ii<ans){
            ans=(a+k)*(b+k)/ii;
            anss=k;
        }
    }
    tmp=a/(a-b);
    if(tmp*(a-b)<a)tmp++;
    k=tmp*(a-b)-a;
    if((a+k)*(b+k)/(a-b)<ans){
            ans=(a+k)*(b+k)/(a-b);
            anss=k;
        }
    cout<<anss;
    cout.flush();
    //system("pause");
    return 0;
}