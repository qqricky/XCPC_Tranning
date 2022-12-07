#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int gcd(int a,int b)
{
    return b ? a : gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
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
        int c,f,b,s;
        cin>>c>>f>>b>>s;
        // double r=(double)c/(2*acos(-1));
        // int x=max(f,b);
        // double len=sqrt(2*r*r*(1-cos(2*acos(-1)/x)));
        // cout<<len*x<<endl;
        // double t=s/(len*x);
        // cout<<t<<endl;
        if(f>b)swap(f,b);
        int flag=1;
        int x;
        if(b%f)flag=0;
        else x=b/f;
        double r=(double)s/(double)c;
        double re=s%c;
        if(re==0.0||!flag){
            cout<<12*ceil(r)<<endl;
            continue;
        }
        int cnt=1;
        double g=(double)x/(double)b*360;
        int num=1;
        while(num*g<re){
            num++;
        }
        double tmp=num*g;
        while(cnt*30<tmp){
            cnt++;
        }
        cout<<12*floor(r)+cnt<<endl;
        
    }
    //system("pause");
    return 0;
}