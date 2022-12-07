#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5070;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int b[N];
struct node
{   
    int a;
    int pos;
    bool operator<(const node y)
    {
        if(a==y.a)return pos<y.pos;
        return a<y.a;
    }
}a[N];
bool cmp(node x,node b)
{
    if(x.a==b.a)
    {
        return x.pos<b.pos;
    }
    return x.a<b.a;
}
int now;
int n;
//贪心
bool ck(int x)
{
    if(now<a[x].a+b[n])return 0;
    int po=n-x+1+1;
    for(int i=1;i<=x;i++){
        if(now<a[i].a+b[po])return 0;
        po++;
    }
    return 1;
}
bool ck2(int x)
{
    if(now>a[x].a+b[1])return 0;
    int po=2;
    for(int i=x+1;i<=n;i++){
        if(now>a[i].a+b[po])return 0;
        po++;
    }
    return 1;
}
int ans[N][2];
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
        int ncnt=0;
        for(int i=1;i<=n;i++){cin>>a[i].a;a[i].pos=i;}
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            now=a[i].a+b[1];
            int l=0,r=n;
            int mid;
            //找最高排位
            while(l<r)
            {
                mid=(l+r+1)>>1;
                if(ck(mid))l=mid;
                else r=mid-1;
            }
            ans[a[i].pos][0]=n-l+1;
            l=1,r=n+1;
            now=a[i].a+b[n];
            //cout<<"so what"<<endl;
            //for(int i=1;i<=n;i++)cout<<ck2(i)<<endl;
            //找最低排位
            while(l<r)
            {
                mid=(l+r)>>1;
                if(ck2(mid))r=mid;
                else l=mid+1;
            }
            int po=1;
            bool f1=0;
            // while(now==a[l].a+b[po]){
            //     if(l==i)f1=1;
            //     l++;
            //     po++;
            // }
            // if(f1)l--;
            ans[a[i].pos][1]=n-l+1;
            //cout<<"What"<<n-l+1<<endl;
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i][0]<<' '<<ans[i][1]<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}