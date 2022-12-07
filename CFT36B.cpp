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
long double xx[N];
long double yy[N];
int f[1070];
ll x,y,n;
double eps=1e-8;
int getfa(int x){
    return x==f[x] ?  x : f[x]=getfa(f[x]);
}
void merge(int a,int b){
    a=getfa(a);
    b=getfa(b);
    if(a==b)return;
    if(a>b)swap(a,b);
    f[a]=b;
}
inline double dis(int a,int b){
    return sqrt(1ll*(xx[a]-xx[b])*(xx[a]-xx[b])+(yy[a]-yy[b])*(yy[a]-yy[b]));
}
bool ck(double len){
    for(int i=1;i<=n+4;i++){
        f[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(xx[i]<=len)merge(i,n+1);
        if((x-xx[i])<=len)merge(i,n+3);
        if(yy[i]<=len)merge(i,n+4);
        if(y-yy[i]<=len)merge(i,n+2);
        for(int j=i+1;j<=n;j++){
            if(dis(i,j)<=2*len){
                merge(i,j);
            }
        }
    }
    int a,b,c,d;
    a=getfa(n+1);
    b=getfa(n+2);
    c=getfa(n+3);
    d=getfa(n+4);
    //cout<<len<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    if(a==d||a==c||b==c||b==d)return 0;
    else return 1;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>y>>n;
    for(int i=1;i<=n;i++){
        cin>>xx[i]>>yy[i];
    }
    double l=0,r=sqrt(x*x+y*y);
    while(r-l>eps){
        double mid=(l+r)/2;
        if(ck(mid)){
            l=mid;
        }
        else r=mid;
    }
    cout<<fixed<<setprecision(7)<<(l+r)/2;
    cout.flush();
    //system("pause");
    return 0;
}