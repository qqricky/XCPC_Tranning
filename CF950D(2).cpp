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
ll n;
ll find(ll before,ll num){
    if(before<=n/2+1)return 2*before-2;
    return find(before-(num+1),num*2+1); 
}
ll get(ll x){
    if(x&1){
        return x/2+1;
    }
    return get(x+(n-x/2));
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    while(q--){
        ll x;
        cin>>x;
        cout<<get(x)<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}