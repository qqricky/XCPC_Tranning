#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
const double eps=1e-6;
int sgn(double d){
    if(fabs(d)<eps)
        return 0;
    else if(d>0){
        return 1;
    }
    return -1;
}
int dcmp(double x,double y)
{
    if(fabs(x-y)<eps)return 0;
    if(x>y)return 1;
    else return -1;
}
struct Point{
    double x, y;
    Point(double x = 0, double y = 0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector A, Vector B){
    return Vector(A.x+B.x, A.y+B.y);
}
Vector operator - (Point A, Point B){
    return Vector(A.x-B.x, A.y-B.y);
}
Vector operator * (Vector A, double p){
    return Vector(A.x*p, A.y*p);
}
Vector operator / (Vector A, double p){
    return Vector(A.x/p, A.y/p);
}
bool operator < (const Point& a, const Point& b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool operator == (const Point& a, const Point& b){
    if(sgn(a.x-b.x) == 0 && sgn(a.y-b.y) == 0)
        return true;
    return false;
}
double Dot(Vector A, Vector B){
    return A.x*B.x + A.y*B.y;
}
double Length(Vector A){
    return sqrt(Dot(A, A));
}
double Angle(Vector A, Vector B){
    return acos(Dot(A, B)/Length(A)/Length(B));
}
double Cross(Vector A, Vector B){
    return A.x*B.y-A.y*B.x;
}
double Area2(Point A, Point B, Point C){
    return fabs(Cross(B-A, C-A));
}
Vector Rotate(Vector A, double rad){//rad为弧度 且为逆时针旋转的角
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal(Vector A){//向量A左转90°的单位法向量
    double L = Length(A);
    return Vector(-A.y/L, A.x/L);
}
bool ToLeftTest(Point a, Point b, Point c){
    return Cross(b - a, c - b) > 0;
}
struct Line{//直线定义
    Point v, p;
    Line(Point v, Point p):v(v), p(p) {}
    Point point(double t){//返回点P = v + (p - v)*t
        return v + (p - v)*t;
    }
};
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
    Vector u = P-Q;
    double t = Cross(w, u)/Cross(v, w);
    return P+v*t;
}
double DistanceToLine(Point P, Point A, Point B){
    Vector v1 = B-A, v2 = P-A;
    return fabs(Cross(v1, v2)/Length(v1));
}
double DistanceToSegment(Point P, Point A, Point B){
    if(A == B)
        return Length(P-A);
    Vector v1 = B-A, v2 = P-A, v3 = P-B;
    if(sgn(Dot(v1, v2)) < 0)
        return Length(v2);
    if(sgn(Dot(v1, v3)) > 0)
        return Length(v3);
    return DistanceToLine(P, A, B);
}
bool OnSegment(Point p, Point a1, Point a2){
    return sgn(Cross(a1-p, a2-p)) == 0 && sgn(Dot(a1-p, a2-p)) < 0;
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
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point a(x1,y1);
        Point b(x2,y2);
        Point c(x3,y3);
        int x0,y0;
        cin>>x0>>y0;
        Point st(x0,y0);
        int f1=OnSegment(st,a,b);
        int f2=OnSegment(st,b,c);
        int f3=OnSegment(st,a,c);
        int f4=(st==a)+(st==b)+(st==c);
        if((f1+f2+f3+f4)==0){
            cout<<-1<<endl;
            continue;
        }
        double ss=Area2(a,b,c);
        ss/=2;
        if(st==c){
            cout<<fixed<<setprecision(9)<<(double)(x1+x2)/2<<' '<<(double)(y1+y2)/2<<endl;
            continue;
        }
        else if(st==b){
            cout<<fixed<<setprecision(9)<<(double)(x1+x3)/2<<' '<<(double)(y1+y3)/2<<endl;
            continue;
        }
        else if(st==c){
            cout<<fixed<<setprecision(9)<<(double)(x2+x3)/2<<' '<<(double)(y3+y2)/2<<endl;
            continue;
        }
        if(f1){
            double tmp1=Area2(a,st,c);
            if(dcmp(tmp1,ss)==0){
                cout<<fixed<<setprecision(9)<<(double)x3<<' '<<(double)y3<<endl;
            }
            else if(tmp1>ss){
                double ans=Length(b-a)*Length(c-a)/(2*Length(a-st));
                double bili=ans/Length(c-a);
                cout<<fixed<<setprecision(9)<<(double)x1+(x3-x1)*bili<<' '<<y1+(y3-y1)*bili<<endl;
            }
            else{
                double ans=Length(b-a)*Length(c-b)/(2*Length(b-st));
                double bili=ans/Length(c-b);
                cout<<fixed<<setprecision(9)<<(double)x2+(x3-x2)*bili<<' '<<y2+(y3-y2)*bili<<endl;
            }
        }
        else if(f2){
            double tmp2=Area2(a,st,b);
            if(dcmp(ss,tmp2)==0){
                cout<<fixed<<setprecision(9)<<(double)x1<<' '<<(double)y1<<endl;
            }
            else if(tmp2>ss){
                double ans=Length(b-a)*Length(c-a)/(2*Length(b-st));
                double bili=ans/Length(a-b);
                cout<<fixed<<setprecision(9)<<(double)x2+(x1-x2)*bili<<' '<<y2+(y1-y2)*bili<<endl;
            }
            else{
                double ans=Length(b-c)*Length(c-a)/(2*Length(c-st));
                double bili=ans/Length(a-c);
                cout<<fixed<<setprecision(9)<<(double)x3+(x1-x3)*bili<<' '<<y3+(y1-y3)*bili<<endl;
            }
        }
        else{
            double tmp3=Area2(a,st,b);
            if(dcmp(tmp3,ss)==0){
                cout<<fixed<<setprecision(9)<<(double)x2<<' '<<(double)y2<<endl;
            }
            else if(tmp3>ss){
                double ans=Length(b-a)*Length(c-a)/(2*Length(a-st));
                double bili=ans/Length(b-a);
                //cout<<bili<<endl;
                //cout<<x1<<"aaa"<<y1<<endl<<x2<<"aaa"<<y2<<endl;
                cout<<fixed<<setprecision(9)<<(double)x1+(x2-x1)*bili<<' '<<y1+(y2-y1)*bili<<endl;
            }
            else{
                double ans=Length(b-c)*Length(c-a)/(2*Length(c-st));
                double bili=ans/Length(b-c);
                cout<<fixed<<setprecision(9)<<(double)x3+(x2-x3)*bili<<' '<<y3+(y2-y3)*bili<<endl;
            }
        }
    }
    //system("pause");
    return 0;
}