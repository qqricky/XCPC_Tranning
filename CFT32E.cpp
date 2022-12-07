#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll c[N]={};
ll ask(int x){
    ll ans=0;
    while(x){
        ans=max(ans,c[x]);
        x-=x&-x;
    }
    return ans;
}
void add(int pos,ll x){
    while(pos<=1e6){
        c[pos]=max(c[pos],x);
        pos+=pos&-pos;
    }
}
ll f[N]={};
int tmm[1070]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,n;
    cin>>a>>n;
    ll ans=0;
    for(int i=1;i<=a;i++){
        int h,d,t;
        cin>>h>>d>>t;
        for(int j=1;j<=t;j++){
            cin>>tmm[j];
        }
        for(int j=t;j>=1;j--){
            int k=tmm[j]+d;
            if(k>n)k=n+1;
            f[k]=max(ask(tmm[j])+h,f[k]);
            add(k,f[k]);
            ans=max(ans,f[k]);
        }
    }
    cout<<ans;
    cout.flush();
    system("pause");
    return 0;
}