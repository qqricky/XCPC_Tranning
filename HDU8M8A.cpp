#include <bits/stdc++.h>
#include <map>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
using namespace std;
const double eps =1e-10;
int sgn(double x)
{
    if(fabs(x<eps))return 0;
    if(x<0)return -1;
    else return 1;
}
struct Point{
    double x,y;
    Point (){}
    Point(double _x,double _y){
        x=_x;
        y=_y;
    }
};
const double pi=acos(-1);
double atrea(Point a, double r1, Point b, double r2)
{
	double d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (d >= r1+r2)
		return 0;
	if (r1>r2)
	{
		double tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
	if(r2 - r1 >= d)
		return pi*r1*r1;
	double ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	double ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
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
        int x1,y1,r1,x2,y2,r2;
        cin>>r1>>x1>>y1>>r2>>x2>>y2;
        int d;
        cin>>d;
        double R1,R2;
        //R1,R2是缩小后的圆
        if(d*d<=r1*r1*2)
            R1=(-d*1.0+sqrt(1.0*4*r1*r1-d*d))/2;
        else R1=0;
        
        if(d*d<=r2*r2*2)
            R2=(-d*1.0+sqrt(1.0*4*r2*r2-d*d))/2;
        else R2=0;
        if(fabs(R1-0)<eps)cout<<"0.000000"<<'\n';
        //求面积交并计算答案
        double ans=atrea(Point(x1,y1),R1,Point(x2,y2),R2)/(pi*R1*R1);
        cout<<fixed<<setprecision(6)<<ans<<'\n';
    }
    //cout<<endl;
    //system("pause");
    return 0;
}