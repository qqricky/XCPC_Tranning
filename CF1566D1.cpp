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


ll n,m;
pair<ll,ll> p[N],a[N];
ll b[N],tr[305];

void add(int x,int y)
{
	while(x<305)
	{
		tr[x] += y;
		x += x&-x;
	}
}
ll sum(int x)
{
	ll res = 0;
	while(x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
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
		cin>>n>>m;
        for(int i=1;i<=n*m;i++) 
        {
            cin>>p[i].first;
            p[i].second = i;
        }
        sort(p+1,p+1+m*n);
        ll res = 0;
        int cnt = 1;
        for(int k=1;k<=n;k++)
        {
            sort(p+(k-1)*m+1,p+k*m+1,[](pair<ll,ll> a,pair<ll,ll> b){
                if(a.first == b.first) return a.second > b.second;
                return a.first < b.first;
            });
            for(int i=1;i<=m;i++)
            {
                a[i].first = p[(k-1)*m+i].second;
                a[i].second = i;
            }
            sort(a+1,a+1+m);
            for(int i=1;i<=m;i++) b[a[i].second] = i;
            memset(tr,0,sizeof tr);
            for(int i=1;i<=m;i++)
            {
                add(b[i],1);
                res += sum(b[i])-1;
            }
	    }
	    cout<<res<<'\n';
	}
	return 0;
}
