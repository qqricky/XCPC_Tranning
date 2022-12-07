#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll x[N],r[N];
struct node
{
    ll l,r;
}nd[N];
bool cmp(node a,node b){
    if(a.l==b.l){
        return a.r>b.r;
    }
    return a.l<b.l;
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
    ll st,sr;
    cin>>st>>sr;
    nd[1].l=st-sr;
    nd[1].r=st+sr;
    for(int i=2;i<=n;i++){
        cin>>x[i]>>r[i];
        nd[i].l=x[i]-r[i];
        nd[i].r=x[i]+r[i];
    }
    ll ans=0;
    sort(nd+1,nd+n+1,cmp);
    ll mx=nd[1].r;
    for(int i=1;i<=n;i++){
        if(nd[i].l<=mx){
            mx=max(mx,nd[i].r);
        }else{
            ans+=nd[i].l-mx;
            mx=max(mx,nd[i].r);
        }
    }
    cout<<ans;
    cout.flush();
    // system("pause");
    return 0;
}