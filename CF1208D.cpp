#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=12e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll c[N]={};
void add(int pos,ll x){
    for(int i=pos;i<=N;i+=(i&-i)){
        c[i]+=x;
    }
}
ll ask(int pos){
    ll res=0;
    for(int i=pos;i;i-=(i&-i)){
        res+=c[i];
    }
    return res;
}
ll s[N];
ll ans[N];
inline bool ck(ll mid,ll x){
    ll val=mid*(mid+1)/2-ask(mid);
    if(val<=x)return 1;
    else return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=n;i>=1;i--){
        int l=0,r=n+1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(ck(mid,s[i]))l=mid;
            else r=mid-1;
        }
        ans[i]=((l+r)>>1)+1;
        add(ans[i],ans[i]);
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout.flush();
    //system("pause");
    return 0;
}