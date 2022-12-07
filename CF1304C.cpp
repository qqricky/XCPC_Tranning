#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
/*
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
*/
struct cus
{
    int ti;
    int l,r;
    bool operator <(const cus& x)
    {
        return ti<x.ti;
    }
}a[105];
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i].ti>>a[i].l>>a[i].r;
        }
        sort(a+1,a+n+1);
        int dur=a[1].ti;
        int d,u;
        u=m+dur;
        d=m-dur;
        int f=1;
        for(int i=1;i<=n;i++){
            if(a[i].r<d||a[i].l>u){
                f=0;
                break;
            }
            d=max(a[i].l,d);
            u=min(a[i].r,u);
            dur=a[i+1].ti-a[i].ti;
            d-=dur;
            u+=dur;
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}