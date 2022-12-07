#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int n;
int ans;
const double delta=0.992;
const double eps=1e-14;
int a,b,c,d;
inline int g(int x){
    int tmp=0;
    while(x){
        tmp+=x%10;
        x/=10;
    }
    return tmp;
}
int calc(int x)
{
    int anss=0;
    int xx=g(x);
    anss=a*x*x*xx+b*x*x+c*x*xx*xx+d*x*xx;
    return anss;
}
void SA()
{
    for(double T=5000;T>=eps;T*=delta){
        int x=rand()%n+1;
        int tmp=calc(x);
        int del=tmp-ans;
        if(del<0){
            ans=tmp;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));srand(rand());srand(rand());
    int t;
    cin>>t;
    while(t--){
        srand(rand());
        cin>>a>>b>>c>>d>>n;
        ans=INF;
        //cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
        while((double)clock()/CLOCKS_PER_SEC<1.0/(t+100))SA();
        cout<<ans<<'\n';
    }
    //cout.flush();
    //system("pause");
    return 0;
}