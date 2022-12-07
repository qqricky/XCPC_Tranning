#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#define ll long long
const int N=1e5+10; 
using namespace std;
double eps=1e-4;
int l,n;
double l1;
double c;
int calc(double x)
{
    double r=(x*x+(double)l*l/4)/(2*x);
    double tmp=2*asin(l/(2*r))*r;
    if(tmp<l1)return 1;
    else return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>l>>n>>c;
    while(l!=-1)
    {
        l1=(1+n*c)*l;
        double ln=0.0;
        double rn=l*0.5;
        while(rn-ln>eps)
        {
            double mid=(ln+rn)/2;
            if(calc(mid))ln=mid;
            else rn=mid;
        }
        cout<<fixed<<setprecision(3)<<ln<<"\n";
        cin>>l>>n>>c;
    }
    //system("pause");
    return 0;
}