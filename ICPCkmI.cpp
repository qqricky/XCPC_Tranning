#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
const double eps=1e-7;
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
    long double x, y;
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
bool cmp(const pair<double,Point> a,const pair<double,Point> b)
{
    return a.first<b.first;
}
int x[1070];
int y[1070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    double lll=min(a1,a2);
    double rrr=max(a1,a2);
    double uuu=max(b1,b2);
    double ddd=min(b1,b2);
    Point st;
    st.x=a1;
    st.y=b1;
    Point ed;
    ed.x=a2;
    ed.y=b2;
    Line l(st,ed);
    vector< pair<double,Point> >ans[1002];
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            Point a11,a22;
            a11.x=x[i];
            a11.y=y[i];
            a22.x=x[j];
            a22.y=y[j];
            Line t(a11,a22);
            // cout<<'i'<<i<<' '<<'j'<<j<<endl;
            // cout<<'f'<<t.p.x<<' '<<t.p.y<<endl;
            // cout<<'s'<<t.v.x<<' '<<t.v.y<<endl;
            if(dcmp(Cross(t.v-t.p,l.v-l.p),0.0)==0)continue;
            Point pt=GetLineIntersection(l.p,l.v-l.p,t.p,t.v-t.p);
            if(dcmp(pt.x,lll)==-1||dcmp(pt.x,rrr)==1)continue;
            if(dcmp(pt.y,ddd)==-1||dcmp(pt.y,uuu)==1)continue;
            // if(i==2&&j==3){
            //     cout<<pt.x<<endl;
            //     cout<<pt.y<<endl;
            // }
            // cout<<'i'<<i<<'j'<<j<<endl;
            // cout<<'X'<<pt.x<<'Y'<<pt.y<<endl;
            if(dcmp(Length(a11-pt),Length(a22-pt))!=-1){
                // cout<<"qqqqqqqqqq";
                // cout<<i<<' '<<j<<endl;
                // cout<<Length(Point(x[i],y[i])-pt)<<endl;
                // cout<<Length(Point(x[j],y[j])-pt)<<endl;
                continue;
            }
            //cout<<pt.x<<"AAAAAAAAAA"<<endl;
            ans[i].push_back(make_pair(Length(pt-st),pt));
        }
        sort(ans[i].begin(),ans[i].end(),cmp);
        int num=0;

        for(int j=1;j<ans[i].size();j++){
            
        }
    }
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        //for(int j=0;j<ans[a].size();j++)cout<<ans[i][j].first<<"aaaa"<<endl;
        if(ans[a].size()<b)cout<<-1<<"\n";
        else {
            //double dd=ans[a][b-1].first/Length(l.p-l.v);
            //cout<<ans[a][b-1].first<<endl;
            cout<<fixed<<setprecision(8)<<ans[a][b-1].second.x<<' '<<ans[a][b-1].second.y<<"\n";
        }
    }
    //system("pause");
    return 0;
}