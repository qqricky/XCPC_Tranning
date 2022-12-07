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
struct node
{
    ll l,r;
}nd[N];
bool cmp(node a,node b){
    if(a.l==b.l){
        return a.r<b.r;
    }
    return a.l<b.r;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        multiset<ll>s;
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>nd[i].l>>nd[i].r;
        }
        sort(nd+1,nd+n+1,cmp);
        ll mx=-1;
        int pos;
        for(int i=1;i<=n;i++){
            if(nd[i].l<=mx){
                pos=i;
                break;
            }
            ans++;
            mx=nd[i].r;
        }
        for(int j=pos-1;j>=1;j--){
            if(nd[j].r>=nd[pos].l)ans--;
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}