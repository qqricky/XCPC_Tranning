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
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;
        y=_y;
    }
    void input(){
        cin>>x>>y;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    double distance(Point p){
        return hypot(x-p.x,y-p.y);
    }
};
struct circle
{
    Point p;
    double r;
    circle(){}
    circle(Point _p,double _r){
        p=_p;
        r=_r;
    }
    circle(double x,double y,double _r){
        p=Point(x,y);
        r=_r;
    }
    int relationcircle(circle v){
        double d = p.distance(v.p);
        if(sgn(d-r-v.r) > 0)return 5;
        if(sgn(d-r-v.r) == 0)return 4;
        double l = fabs(r-v.r);
        if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3;
        if(sgn(d-l)==0)return 2;
        if(sgn(d-l)<0)return 1;
    }
};
int xx[N],yy[N],rr[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int m,r;
        cin>>m>>r;
        double ans=2.0*pi*r;
        for(int i=1;i<=m;i++){
            cin>>xx[i]>>yy[i]>>rr[i];
            Point p{xx[i],yy[i]};
            double dis=p.distance((Point){0,0});
            if(dis+rr[i]<r)continue;
            if(dis-rr[i]>r)continue;
            double co=(dis*dis+1.0*rr[i]*rr[i]-1.0*r*r)/(2*dis*rr[i]);
            double coo=(dis*dis-1.0*rr[i]*rr[i]+1.0*r*r)/(2.0*dis*r);
            double thi=acos(coo);
            thi*=2.0;
            double sub=thi*r;
            double alp=acos(co);
            double belta=2*(pi-alp);
            double add=2.0*rr[i]*(pi-0.5*belta);
            ans+=add-sub;
        }
        cout<<fixed<<setprecision(7)<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}