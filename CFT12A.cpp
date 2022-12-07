#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define double long double
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
    return Cross(B-A, C-A);
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
Point GetLineProjection(Point P, Point A, Point B){
    Vector v = B-A;
    return A+v*(Dot(v, P-A)/Dot(v, v));
}
bool OnSegment(Point p, Point a1, Point a2){
    return sgn(Cross(a1-p, a2-p)) == 0 && sgn(Dot(a1-p, a2-p)) < 0;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2){
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);
    double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    //if判断控制是否允许线段在端点处相交，根据需要添加
    if(!sgn(c1) || !sgn(c2) || !sgn(c3) || !sgn(c4)){
        bool f1 = OnSegment(b1, a1, a2);
        bool f2 = OnSegment(b2, a1, a2);
        bool f3 = OnSegment(a1, b1, b2);
        bool f4 = OnSegment(a2, b1, b2);
        bool f = (f1|f2|f3|f4);
        return f;
    }
    return (sgn(c1)*sgn(c2) < 0 && sgn(c3)*sgn(c4) < 0);
}
double xx,yy;
bool cmp(Point a,Point b)
{
    if(atan2(a.y-yy,a.x-xx)!=atan2(b.y-yy,b.x-xx))
        return (atan2(a.y-yy,a.x-xx))<(atan2(b.y-yy,b.x-xx));
    return a.x<b.x;
}
Point vex[2*N];
int ma[N];
int mi[N];
int a[N];
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
        int n;
        cin>>n;
        if(n<=2){
            cout<<0<<endl;
            continue;
        }
        memset(mi,0x3f,sizeof(int)*(n+3));
        memset(ma,0,sizeof(int)*(n+3));
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=n;i>=1;i--){
            ma[i]=max(ma[i+1],a[i]);
            mi[i]=min(mi[i+1],a[i]);
        }
        int pos;
        xx=INF;
        yy=INF;
        int ncnt=0;
        for(int i=1;i<n;i++){
            if(ma[i+1]==mi[i+1]){
                vex[++ncnt].x=a[i];
                vex[ncnt].y=ma[i+1];
                if(vex[ncnt].y<yy){
                    pos=ncnt;
                    xx=vex[ncnt].x;
                    yy=vex[ncnt].y;
                }
                else if(!dcmp(yy,vex[ncnt].y)){
                    if(xx>vex[ncnt].x){
                        xx=vex[ncnt].x;
                        pos=ncnt;
                    }
                }
            }
            else{
                vex[++ncnt].x=a[i];
                vex[ncnt].y=ma[i+1];
                if(vex[ncnt].y<yy){
                    pos=ncnt;
                    xx=vex[ncnt].x;
                    yy=vex[ncnt].y;
                }
                else if(!dcmp(yy,vex[ncnt].y)){
                    if(xx>vex[ncnt].x){
                        xx=vex[ncnt].x;
                        pos=ncnt;
                    }
                }
                vex[++ncnt].x=a[i];
                vex[ncnt].y=mi[i+1];
                if(vex[ncnt].y<yy){
                    pos=ncnt;
                    xx=vex[ncnt].x;
                    yy=vex[ncnt].y;
                }
                else if(!dcmp(yy,vex[ncnt].y)){
                    if(xx>vex[ncnt].x){
                        xx=vex[ncnt].x;
                        pos=ncnt;
                    }
                }
            }
        }
        Point tmp;
        tmp=vex[1];
        vex[1]=vex[pos];
        vex[pos]=tmp;
        sort(vex+2,vex+ncnt+1,cmp);
        //for(int i=1;i<=n;i++)cout<<vex[i].x<<' '<<vex[i].y<<endl;
        pos=0;
        int s[2*N];
        s[++pos]=1;
        s[++pos]=2;
        for(int i=3;i<=ncnt;i++){
            while(pos>=2&&!ToLeftTest(vex[s[pos-1]],vex[s[pos]],vex[i])){
                pos--;
            }
            s[++pos]=i;
        }
        ll ans=0;
        Vector vv={vex[s[2]]-vex[s[1]]};
        //cout<<vex[s[1]].x<<"  "<<vex[s[1]].y<<endl;
        //cout<<vex[s[2]].x<<"  "<<vex[s[2]].y<<endl;
        for(int i=3;i<=pos;i++){
            //cout<<vex[s[i]].x<<"  "<<vex[s[i]].y<<endl;
            ans+=fabs(Cross(vex[s[i]]-vex[s[i-1]],vv));
            vv=vv+(vex[s[i]]-vex[s[i-1]]);
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}