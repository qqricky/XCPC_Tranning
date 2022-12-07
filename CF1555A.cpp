#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
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
        ll n;
        cin>>n;
        if(n<=6){
            cout<<15<<endl;
            continue;
        }
        if(n&1)n++;
        cout<<n/2*5<<endl;
    }
    //system("pause");
    return 0;
}