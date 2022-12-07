#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
double eps=1e-6;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,r;
        cin>>a>>b>>c>>r;
        ll x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        double A=x1-a;
        double B=y1-b;
        double C=z1-c;
        double t1=x2-x1;
        double t2=y2-y1;
        double t3=z2-z1;
        double aa=t1*t1+t2*t2+t3*t3;
        double bb=2*A*t1+2*B*t2+2*C*t3;
        double cc=A*A+B*B+C*C-r*r;
        double delta=bb*bb-4*aa*cc;
        double res=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
        if(delta<=0+eps){
            double ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
            std::cout<<fixed<<setprecision(8)<<ans<<'\n';
        }else{
            double k1=(-bb-sqrt(delta))/(2*aa);
            double k2=(-bb+sqrt(delta))/(2*aa);
            if((k1>=1&&k2>=1)||(k1<=0&&k2<=0)){
                double ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
                std::cout<<fixed<<setprecision(8)<<ans<<'\n';
                continue;
            }
            double ans=0;
            double dis1=sqrt((a-x1)*(a-x1)+(b-y1)*(b-y1)+(c-z1)*(c-z1));
            double dis2=sqrt((a-x2)*(a-x2)+(b-y2)*(b-y2)+(c-z2)*(c-z2));
            ans+=sqrt(dis1*dis1-r*r)+sqrt(dis2*dis2-r*r);
            double thi1=acos(r*1.0/dis1);
            double thi2=acos(r*1.0/dis2);
            double dis3=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
            double alpha=acos((dis1*dis1+dis2*dis2-dis3*dis3)/(2*dis1*dis2));
            double deg=alpha-thi1-thi2;
            ans+=deg*r;
            // double nx1=x1+k1*(x2-x1);
            // double ny1=y1+k1*(y2-y1);
            // double nz1=z1+k1*(z2-z1);
            // double nx2=x1+k2*(x2-x1);
            // double ny2=y1+k2*(y2-y1);
            // double nz2=z1+k2*(z2-z1);
            // double ans=0;
            // double tmp1=sqrt((nx1-x1)*(nx1-x1)+(ny1-y1)*(ny1-y1)+(nz1-z1)*(nz1-z1));
            // double tmp2=sqrt((nx2-x2)*(nx2-x2)+(ny2-y2)*(ny2-y2)+(nz2-z2)*(nz2-z2));
            // ans+=tmp1+tmp2;
            // std::cout<<fixed<<setprecision(8)<<tmp1<<' '<<tmp2<<'\n';
            // double dianji=(nx1-a)*(nx2-a)+(ny1-b)*(ny2-b)+(nz1-c)*(nz2-c);
            // double xx=sqrt((nx1-a)*(nx1-a)+(ny1-b)*(ny1-b)+(nz1-c)*(nz1-c));
            // double yy=sqrt((nx2-a)*(nx2-a)+(ny2-b)*(ny2-b)+(nz2-c)*(nz2-c));
            // double thi=acos(dianji/(xx*yy));
            // ans+=r*thi;
            // cout<<thi<<'\n';
            // cout<<fixed<<setprecision(8)<<res<<'\n';
            std::cout<<fixed<<setprecision(8)<<ans<<'\n';
        }
    }
    // std::cout.flush();
    // std::system("pause");
    return 0;
}