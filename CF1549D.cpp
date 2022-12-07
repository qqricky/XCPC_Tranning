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
ll a[N];
ll st[N][30];
int n;
ll gcd(ll x,ll y)
{
    return y ? gcd(y,x%y) : x;
}
ll query(int l,int r)
{
    int k=log2(r-l+1);
    return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
bool ck(int x)
{
    for(int i=1;i+x-1<n;i++){
        if(query(i,i+x-1)>1)return 1;
    }
    return 0;
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
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i-1]=abs(a[i]-a[i-1]);
        }
        for(int i=1;i<n;i++)st[i][0]=a[i];
        for(int j=1;j<=log2(n);j++){
            for(int i=1;i+(1<<j)-1<n;i++){
                st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
        int l=0,r=n+1;
        int mid;
        while(l+1<r){
            mid=(r+l)>>1;
            if(ck(mid))l=mid;
            else r=mid;
        }
        cout<<l+1<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}